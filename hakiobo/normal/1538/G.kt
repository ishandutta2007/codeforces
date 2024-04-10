import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        var (x, y) = run {
            val x = br.readInt().toLong()
            val y = br.readInt().toLong()
            min(x, y) to max(x, y)
        }

        val (a, b) = run {
            val a = br.readInt().toLong()
            val b = br.readInt().toLong()
            min(a, b) to max(a, b)
        }
        if (a == b) {
            val ans = min(x / a, y / a)
            sb.appendLine(ans)
        } else {
            val base = min(x / a, (x + y) / (a + b))
            val dif = b - a
            x -= base * a
            y -= base * b
            val maxXChange = x / dif
            val neededYChange = if (y >= 0) 0 else (dif - y - 1) / dif
            sb.appendLine(base - max(0, neededYChange - maxXChange))
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