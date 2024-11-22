#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers { _MAIN = 0, _LOWER, _RAISE, _ADJUST };

/* clang-format off */

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_MAIN] = LAYOUT_60_tsangan_hhkb(
  KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, LOWER, 
           _______, KC_LGUI, KC_LALT,                        KC_SPC,                   KC_RALT, RAISE, _______
),

[_LOWER] = LAYOUT_60_tsangan_hhkb(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
  _______, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, KC_DEL,
  _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_PGDN, KC_DOWN, _______, _______,
           _______, _______, _______,                      _______,                         _______, _______, _______
),

[_RAISE] = LAYOUT_60_tsangan_hhkb(
  QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
  QK_MAKE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______,                      	_______,                        _______, _______, _______
),

[_ADJUST] = LAYOUT_60_tsangan_hhkb(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  QK_MAKE, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______,                      	_______,                        _______, _______, _______
)

};
/* clang-format off */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
