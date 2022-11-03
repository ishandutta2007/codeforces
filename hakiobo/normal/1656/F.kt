import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

private fun calcCost(a: Long, b: Long, t: Long): Long {
    return (a + t) * (b + t) - t * t
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    repeat(br.readInt()) {
        val n = br.readInt()
        val a = LongArray(n) { br.readInt().toLong() }.sorted().toLongArray()
        var sum = a[0]
        for (i in 1 until n) {
            sum += a[i]
        }
        if (sum + a[0] * (n - 2) > 0 || sum + a[n - 1] * (n - 2) < 0) {
            bw.append("INF\n")
        } else {
            var nonTPart = (sum - a[0]) * a[0]
            var tPart = (n - 1) * a[0] + (sum - a[0])
            var bestAns = nonTPart - tPart * a[0]

            for (i in 1 until n - 1) {
                nonTPart += (a[n - 1] - a[0]) * a[i]
                tPart += a[n - 1] - a[0]

                bestAns = max(bestAns, nonTPart - tPart * a[i])
            }
            bw.append("${bestAns}\n")
        }
    }
    bw.flush()
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