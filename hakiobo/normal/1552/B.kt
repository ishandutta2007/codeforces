import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val ratings = Array(n) { IntArray(5) { br.readInt() } }
        fun isBetter(a: Int, b: Int): Boolean {
            var ct = 0
            for (x in 0 until 5) {
                if (ratings[a][x] < ratings[b][x]) {
                    ct++
                }
            }
            return ct >= 3
        }

        var best = 0
        for (x in 1 until n) {
            if (isBetter(x, best)) {
                best = x
            }
        }
        var good = true
        for (x in 0 until n) {
            if (isBetter(x, best)) {
                good = false
            }
        }
        if (good) {
            sb.appendLine(best + 1)
        } else {
            sb.appendLine(-1)
        }
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