import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt().toLong()
        val a = LongArray(n) { br.readInt().toLong() }
        val ans = if (k >= n) {
            a.sum() + k * n - ((n * (n + 1L)) shr 1)

        } else {
            var curSum = 0L

            for (i in 0 until k.toInt()) {
                curSum += a[i]
            }
            var maxSum = curSum
            for (i in k.toInt() until n) {
                curSum += a[i] - a[i - k.toInt()]
                maxSum = max(maxSum, curSum)
            }

            maxSum + ((k * (k - 1)) shr 1)
        }
        bw.appendLine(ans.toString())

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