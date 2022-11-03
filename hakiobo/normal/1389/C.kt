import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val line = br.readLine()
        val cts = Array(10) { IntArray(10) }
        val expectingSecond = Array(10) { BooleanArray(10) }
        for (c in line) {
            val digit = c - '0'
            for (x in 0 until 10) {
                if (x != digit) {
                    if (expectingSecond[x][digit]) {
                        expectingSecond[x][digit] = false
                        cts[x][digit]++
                    }
                    if (!expectingSecond[digit][x]) {
                        expectingSecond[digit][x] = true
                        cts[digit][x]++
                    }
                } else {
                    cts[digit][digit]++
                }
            }
        }
        var most = 0
        for (x in 0 until 10) {
            for (y in 0 until 10) {
                if (x != y && cts[x][y] and 1 == 1) {
                    cts[x][y]--
                }
                most = most.coerceAtLeast(cts[x][y])
            }
        }
        sb.append(line.length - most).append('\n')
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}