import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val nums = Array(n) {
            LongArray(m) { br.readLong() }
        }
        val sums = LongArray(n)
        var highIdx = 0
        var low = Long.MAX_VALUE
        for (i in 0 until n) {
            for (j in 0 until m) {
                sums[i] += nums[i][j] * j
            }
            if (sums[i] > sums[highIdx]) highIdx = i

            low = min(low, sums[i])
        }
        bw.appendLine("${highIdx + 1} ${sums[highIdx] - low}")
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

private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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