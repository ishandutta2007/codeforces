fun main() {
    val (row, col) = System.`in`.bufferedReader().readLine().split(' ').map(String::toInt)
    val out = when (row) {
        0 -> {
            when (col) {
                26, 28, in 30..35, 37 -> false
                else -> true
            }
        }
        1 -> {
            when (col) {
                22, in 24..26, 28, 30, 32, 35, in 37..41 -> false
                else -> true
            }
        }
        2 -> {
            when (col) {
                in 20..22, 24, 28, in 32..33, 35, 40, 43 -> false
                else -> true
            }
        }
        3 -> {
            when (col) {
                in 17..20, 22, 24, in 26..30, in 35..38, 40, in 42..44, 46 -> false
                else -> true
            }
        }
        4 -> {
            when (col) {
                in 16..17, 24, 26, in 32..35, 40, 42, 44, in 46..47 -> false
                else -> true
            }
        }
        5 -> {
            when (col) {
                14, in 17..18, in 20..24, in 26..28, in 30..32, 34, 37, in 39..40, 44, 47, 49 -> false
                else -> true
            }
        }
        6 -> {
            when (col) {
                in 13..15, 18, 21, 28, 30, in 34..37, in 40..41, in 43..44, in 46..47, in 49..50 -> false
                else -> true
            }
        }
        7 -> {
            when (col) {
                in 11..16, in 18..19, in 21..22, in 24..26, in 28..30, in 32..34, in 39..40, 43, 46, in 50..52 -> false
                else -> true
            }
        }
        8 -> {
            when (col) {
                in 10..21, 26, 32, 36, in 38..39, in 42..43, in 45..46, 48, in 51..53 -> false
                else -> true
            }
        }
        9 -> {
            when (col) {
                in 9..28, in 30..36, in 39..42, in 45..54 -> false
                else -> true
            }
        }
        10 -> {
            when (col) {
                in 8..55 -> false
                else -> true
            }
        }
        11, 12 -> {
            when (col) {
                in 7..56 -> false
                else -> true
            }
        }
        13 -> {
            when (col) {
                in 6..57 -> false
                else -> true
            }
        }
        14, 15 -> {
            when (col) {
                in 5..58 -> false
                else -> true
            }
        }
        16 -> {
            when (col) {
                in 4..59 -> false
                else -> true
            }
        }
        17 -> {
            when (col) {
                in 3..60 -> false
                else -> true
            }
        }
        18 -> {
            when (col) {
                in 5..60 -> false
                else -> true
            }
        }
        19 -> {
            when (col) {
                in 7..18, 22, in 25..38, 42, 44, in 46..58 -> false
                else -> true
            }
        }
        20 -> {
            when (col) {
                in 2..3, in 9..17, 20, in 24..38, 40, in 48..55 -> false
                else -> true
            }
        }
        21 -> {
            when (col) {
                in 2..5, in 11..15, in 19..20, 22, in 26..40, in 42..43, in 45..46, 49, in 51..52, in 60..61 -> false
                else -> true
            }
        }
        22 -> {
            when (col) {
                in 1..7, 13, in 17..19, in 22..24, in 27..37, 39, 42, in 46..47, in 57..62 -> false
                else -> true
            }
        }
        23 -> {
            when (col) {
                in 1..9, 15, 18, in 21..22, in 24..25, in 29..37, in 39..40, in 42..46, 49, in 54..62 -> false
                else -> true
            }
        }
        24 -> {
            when (col) {
                in 1..12, in 14..15, in 17..19, in 25..27, in 30..36, 40, 43, in 48..50, in 52..62 -> false
                else -> true
            }
        }
        25 -> {
            when (col) {
                in 1..9, 15, in 19..21, in 23..25, in 29..36, 38, in 40..44, 46, 50, 53, in 55..62 -> false
                else -> true
            }
        }
        26 -> {
            when (col) {
                in 0..11, in 13..15, 17, 20, 23, 27, in 30..35, 38, 41, in 46..47, in 49..51, in 55..63 -> false
                else -> true
            }
        }
        27 -> {
            when (col) {
                in 0..10, 14, 17, in 19..20, in 21..24, in 26..28, in 30..33, 35, in 37..39, in 41..44, in 47..49, 53, in 55..63 -> false
                else -> true
            }
        }
        28 -> {
            when (col) {
                in 0..10, in 12..17, in 19..22, 27, 30, 32, 37, 39, 42, in 44..47, in 51..53, in 55..63 -> false
                else -> true
            }
        }
        29 -> {
            when (col) {
                in 0..10, 16, 19, in 22..24, in 26..28, 32, 34, in 36..37, in 39..40, 42, 45, 49, 52, in 55..63 -> false
                else -> true
            }
        }
        30 -> {
            when (col) {
                in 0..11, in 13..14, in 16..19, in 21..22, in 24..26, 30, in 32..34, in 40..43, 45, in 47..52, in 54..63 -> false
                else -> true
            }
        }
        31 -> {
            when (col) {
                in 0..10, in 14..16, 19, 22, in 26..28, 30, in 33..35, in 37..40, 43, in 45..47, 51, in 55..63 -> false
                else -> true
            }
        }
        32 -> {
            when (col) {
                in 0..12, in 18..19, in 21..23, in 25..26, in 28..30, in 32..33, 39, in 42..43, in 45..46, 49, 53, in 55..63 -> false
                else -> true
            }
        }
        33 -> {
            when (col) {
                in 0..13, in 15..16, 18, 23, 25, 30, 32, 35, 37, in 39..40, 42, in 46..47, in 49..50, in 52..63 -> false
                else -> true
            }
        }
        34 -> {
            when (col) {
                in 0..11, in 16..19, 21, 23, 25, 27, in 29..32, in 34..35, 37, 40, in 42..44, in 47..49, in 53..63 -> false
                else -> true
            }
        }
        35 -> {
            when (col) {
                in 0..12, 14, 17, in 21..23, in 27..30, 34, in 37..38, 43, in 46..47, in 51..63 -> false
                else -> true
            }
        }
        36 -> {
            when (col) {
                in 0..15, in 19..21, 25, in 27..28, in 30..31, in 33..34, in 36..37, 40, in 42..44, 46, 49, in 52..63 -> false
                else -> true
            }
        }
        37 -> {
            when (col) {
                in 0..17, 21, in 23..28, in 34..40, 44, in 48..63 -> false
                else -> true
            }
        }
        38 -> {
            when (col) {
                in 1..16, 19, in 24..28, 30, in 32..42, 46, in 49..62 -> false
                else -> true
            }
        }
        39 -> {
            when (col) {
                in 1..30, in 35..62 -> false
                else -> true
            }
        }
        40 -> {
            when(col){
                in 1..27, 29, 32, in 34..62 -> false
                else -> true
            }
        }
        41 -> {
            when (col) {
                in 1..25, 27, in 31..62 -> false
                else -> true
            }
        }
        42 -> {
            when (col) {
                in 2..25, 29, in 33..61 -> false
                else -> true
            }
        }
        43 -> {
            when (col) {
                in 2..8, in 11..29, in 31..61 -> false
                else -> true
            }
        }
        44 -> {
            when (col) {
                in 3..9, 11, in 13..28, in 32..52, in 54..60 -> false
                else -> true
            }
        }
        45 -> {
            when (col) {
                in 3..9, 13, in 17..27, 30, in 32..42, in 44..48, 50, in 55..60 -> false
                else -> true
            }
        }
        46 -> {
            when (col) {
                in 3..9, 11, 13, 15, 18, 20, in 24..25, 27, in 29..30, 33, 35, 38, in 40..41, in 45..46, 52, in 54..60 -> false
                else -> true
            }
        }
        47 -> {
            when (col) {
                in 4..11, in 15..16, 22, in 30..31, in 35..36, 43, 45, in 48..50, in 52..59 -> false
                else -> true
            }
        }
        48 -> {
            when (col) {
                in 5..11, 13, in 16..19, in 21..24, in 26..28, in 31..33, in 38..40, in 42..46, 48, in 50..58 -> false
                else -> true
            }
        }
        49 -> {
            when (col) {
                in 5..14, 16, 19, 22, 26, in 28..31, in 33..35, in 37..38, 40, 46, in 50..58 -> false
                else -> true
            }
        }
        50 -> {
            when (col) {
                in 6..13, in 18..19, in 21..22, 24, 29, 33, 35, in 40..42, 44, in 48..57 -> false
                else -> true
            }
        }
        51 -> {
            when (col) {
                in 7..15, in 17..18, in 22..26, in 28..29, 31, 33, 37, in 39..40, in 44..56 -> false
                else -> true
            }
        }
        52 -> {
            when (col) {
                in 7..15, in 18..20, 23, 25, in 29..31, 35, in 37..39, 42, in 46..56 -> false
                else -> true
            }
        }
        53 -> {
            when (col) {
                in 8..16, in 20..23, in 27..29, in 31..32, in 34..37, in 39..42, in 44..55 -> false
                else -> true
            }
        }
        54 -> {
            when (col) {
                in 9..17, in 19..20, 25, 27, 34, 39, in 41..54 -> false
                else -> true
            }
        }
        55 -> {
            when (col) {
                in 10..21, 23, in 25..28, in 30..31, in 33..34, 36, in 38..39, in 42..53 -> false
                else -> true
            }
        }
        56 -> {
            when (col) {
                in 11..23, in 28..31, 36, in 41..52 -> false
                else -> true
            }
        }
        57 -> {
            when (col) {
                in 13..32, in 34..50 -> false
                else -> true
            }
        }
        58 -> {
            when (col) {
                in 14..49 -> false
                else -> true
            }
        }
        59 -> {
            when (col) {
                in 16..47 -> false
                else -> true
            }
        }
        60 -> {
            when (col) {
                in 17..46 -> false
                else -> true
            }
        }
        61 -> {
            when (col) {
                in 20..43 -> false
                else -> true
            }
        }
        62 -> {
            when (col) {
                in 22..41 -> false
                else -> true
            }
        }
        63 -> {
            when (col) {
                in 26..37 -> false
                else -> true
            }
        }
        else -> true
    }

    if(out){
        print("OUT")
    } else {
        print("IN")
    }
}