import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val lows = LongArray(n)
        val highs = LongArray(n) { i ->
            lows[i] = br.readInt().toLong()
            br.readInt().toLong()
        }
        val cons = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u] += v
            cons[v] += u
        }
        val dpL = LongArray(n)
        val dpH = LongArray(n)
        val parents = IntArray(n) { -1 }
        fun r(node: Int) {
            for (child in cons[node]) {
                if (child != parents[node]) {
                    parents[child] = node
                    r(child)
                    dpH[node] += max(
                        (highs[node] - highs[child]).absoluteValue + dpH[child],
                        (highs[node] - lows[child]).absoluteValue + dpL[child]
                    )
                    dpL[node] += max(
                        (lows[node] - highs[child]).absoluteValue + dpH[child],
                        (lows[node] - lows[child]).absoluteValue + dpL[child]
                    )
                }
            }
        }
        r(0)
        sb.appendLine(max(dpH[0], dpL[0]))
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