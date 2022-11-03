import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val nums = IntArray(n) { br.readInt() - 1 }
        val neededRemoved = IntArray(n) { idx -> idx - nums[idx] }
        val dp = IntArray(n)
        var ans = Int.MAX_VALUE
        for (x in 0 until n) {
            if (neededRemoved[x] < 0) continue
            dp[x] = 1
            for (y in 0 until x) {
                if (neededRemoved[y] <= neededRemoved[x] && x - y > neededRemoved[x] - neededRemoved[y]) {
                    dp[x] = max(dp[x], dp[y] + 1)
                }
            }
            if (dp[x] == k) ans = min(ans, neededRemoved[x])
        }
        sb.appendLine(if (ans == Int.MAX_VALUE) -1 else ans)
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