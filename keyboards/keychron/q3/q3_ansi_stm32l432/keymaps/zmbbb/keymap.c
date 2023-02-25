/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "sendstring_german.h"

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_L2
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA,
    ZMB_BOOT,               //Restart into bootloader after hold timeout
    ZMB_CDS,               //Send string "Connected Digital Services"
    ZMB_EMB,               //Send string "andreas.renner@pwc.com"
    ZMB_EMP,               //Send string "arenner@gmail.com"
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_87(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_87(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_87(
        KC_ESC,                KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        MO(WIN_L2),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,     KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_NUBS,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_87(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_MPLY,  KC_MSTP,  KC_VOLU,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_MPRV,  KC_MNXT,  KC_VOLD,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  ZMB_BOOT, NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_L2] = LAYOUT_ansi_87(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,
        _______,  KC_CALC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,
        _______,  _______,  _______,  ZMB_EMB,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,
        _______,  ZMB_EMP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  ZMB_CDS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  KC_KP_0,  KC_PDOT,  KC_PENT),
};

// clang-format on

static uint32_t time;

void matrix_scan_user(void) {
    if (time && sync_timer_elapsed32(time) >= 500) {
        time = 0;
        unregister_code(KC_LCMD);
        unregister_code(KC_SPACE);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed && time == 0) {
                register_code(KC_LCMD);
                register_code(KC_SPACE);
                time = sync_timer_read32();
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        case ZMB_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        /* ZMB Section */
        case ZMB_CDS:
            if (record->event.pressed) {
                SEND_STRING("Connected Digital Services");
            }
            return false;
        case ZMB_EMB:
            if (record->event.pressed) {
                SEND_STRING("andreas.renner@pwc.com");
            }
            return false;
        case ZMB_EMP:
            if (record->event.pressed) {
                SEND_STRING("arenner@gmail.com");
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}


/* RGB Matrix Effects */
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // /* MVKB Terminal keycaps */
    // HSV HSV_MAIN = {8, 250, 255};   // orange
    // HSV HSV_MODIFIERS = {40, 250, 255}; // green
    // HSV HSV_LAYER = {0, 0, 255};    // white
    // RGB RGB_SCROLL_LOCK = RGB_RED

    /* ACGAM Pink Indigo keycaps */
    HSV HSV_MAIN = {8, 180, 255};   // warm white
    HSV HSV_MODIFIERS = {254, 210, 255}; // pink
    HSV HSV_LAYER = {7, 255, 255};    // 
    // RGB RGB_SCROLL_LOCK = RGB_GREEN


    RGB RGB_MAIN;
    RGB RGB_MODIFIERS;
    RGB RGB_LAYER;

    RGB_LAYER = hsv_to_rgb(HSV_LAYER);
    
    if (layer_state_is(WIN_FN)) {
        // RGB_MAIN = hsv_to_rgb(HSV_LAYER);
        // RGB_MODIFIERS = hsv_to_rgb(HSV_MODIFIERS);
        RGB_MAIN = hsv_to_rgb(HSV_MAIN);
        RGB_MODIFIERS = hsv_to_rgb(HSV_MAIN);
    }
    else if (layer_state_is(WIN_L2)) {
        // RGB_MAIN = hsv_to_rgb(HSV_MAIN);
        // RGB_MODIFIERS = hsv_to_rgb(HSV_LAYER);
        RGB_MAIN = hsv_to_rgb(HSV_MAIN);
        RGB_MODIFIERS = hsv_to_rgb(HSV_MAIN);
    }
    else {
        RGB_MAIN = hsv_to_rgb(HSV_MAIN);
        RGB_MODIFIERS = hsv_to_rgb(HSV_MODIFIERS);
    }

    /* Set background led for all keys */
    for (uint8_t i = led_min; i <= led_max; i++) {
        // if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER) && i != 16) {
        //     rgb_matrix_set_color(i, RGB_MODIFIERS.r, RGB_MODIFIERS.g, RGB_MODIFIERS.b);
        // }
        // else {
        //     rgb_matrix_set_color(i, RGB_MAIN.r, RGB_MAIN.g, RGB_MAIN.b);
        // }

        switch(i) {
            case 0:     // ESC
            case 62:    // RETURN
            case 75:    // ARROW UP
            case 79:    // SPACE
            case 84:    // ARROW LEFT
            case 85:    // ARROW DOWN
            case 86:    // ARROW RIGHT
                rgb_matrix_set_color(i, RGB_MODIFIERS.r, RGB_MODIFIERS.g, RGB_MODIFIERS.b);
                break;
            default:
                rgb_matrix_set_color(i, RGB_MAIN.r, RGB_MAIN.g, RGB_MAIN.b);
                break;
        }
    }


    /* Highlight active keys for non-default layers in layer color */
    if (layer_state_is(WIN_FN) || layer_state_is(WIN_L2)) {
        for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
            for (uint8_t c = 0; c < MATRIX_COLS; c++) {
                uint16_t keycode;
                uint8_t index;

                if(layer_state_is(WIN_FN))
                    keycode = keymaps[WIN_FN][r][c];
                else if (layer_state_is(WIN_L2))
                    keycode = keymaps[WIN_L2][r][c];

                if((keycode == KC_NO) || (keycode == KC_TRANSPARENT))
                    continue;
                
                index = g_led_config.matrix_co[r][c];

                rgb_matrix_set_color(index, RGB_LAYER.r, RGB_LAYER.g, RGB_LAYER.b);
            }
        }
    }


    /* Scroll lock indicator */
    if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, RGB_GREEN);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_RED);
    }
}
