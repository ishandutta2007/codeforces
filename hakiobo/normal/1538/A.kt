import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val powers = IntArray(n) { br.readInt() }
        var maxIdx = 0
        var minIdx = 0
        for (idx in 1 until n) {
            if (powers[idx] < powers[minIdx]) {
                minIdx = idx
            }
            if (powers[idx] > powers[maxIdx]) {
                maxIdx = idx
            }
        }

        var cost = max(minIdx, maxIdx) + 1
        cost = min(cost, max(n - minIdx, n - maxIdx))
        cost = min(cost, minIdx + 1 + n - maxIdx)
        cost = min(cost, maxIdx + 1 + n - minIdx)
        sb.appendLine(cost)
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