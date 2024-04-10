import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readLine()
        val b = br.readLine()
        var sum = 0
        var state = -1
        for (x in 0 until n) {
            if (a[x] == b[x]) {
                if (a[x] == '0') {
                    if (state == 1) {
                        sum += 2
                        state = -1
                    } else if (state == 0) {
                        sum++
                    } else {
                        state = 0
                    }
                } else {
                    if (state == 0) {
                        sum += 2
                        state = -1
                    } else {
                        state = 1
                    }
                }
            } else {
                sum += 2
                if (state == 0) sum++
                state = -1
            }
        }
        if (state == 0) {
            sum++
        }
        sb.appendLine(sum)
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