import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val positions = IntArray(n)
    val powers = IntArray(n) { idx ->
        positions[idx] = br.readInt()
        br.readInt()
    }
    val sorted = IntArray(n) { it }.sortedBy { positions[it] }
    val dp = IntArray(n)
    dp[0] = 0
    var ans = n - 1
    for (x in 1 until n) {
        var high = x
        var low = 0
        val spot = positions[sorted[x]]
        val power = powers[sorted[x]]
        while (low < high) {
            val mid = (high + low) shr 1
            if (positions[sorted[mid]] + power >= spot) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        if (low == 0) {
            dp[x] = x
        } else {
            dp[x] = x - low + dp[low - 1]
        }
        ans = min(ans, n - 1 - x + dp[x])
    }
    print(ans)
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