import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val p = br.readInt()
    val a = IntArray(n) { br.readInt() }.sorted()
    var low = 0
    var high = 1_000_000_000
    for (x in a.indices.reversed()) {
        val v = a[x]
        val needed = v - x
        low = low.coerceAtLeast(needed)
        if (p <= x + 1) {
            high = high.coerceAtMost(needed + p - 1)
        }
    }
    sb.append(max(high - low, 0)).append('\n')
    for (x in low until high) {
        sb.append(x).append(' ')
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