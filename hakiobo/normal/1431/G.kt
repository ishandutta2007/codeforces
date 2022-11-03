import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()
    val nums = IntArray(n) { br.readInt() }.sorted()

    val dp = Array(n) { IntArray(n) { -1 } }
    val dp2 = Array(n) { IntArray(k + 1) { -1 } }
    fun solve(idx: Int, movesLeft: Int): Int {
        if (idx >= n) return 0
        if (dp2[idx][movesLeft] == -1) {
            if (2 * movesLeft + idx > n) {
                return 0
            }
            var best = solve(idx + 1, movesLeft)
            for (x in 1..movesLeft) {
                val high = idx + 2 * x - 1
                if (dp[idx][high] == -1) {
                    var lower = 0
                    var higher = 0
                    for (i in idx until idx + x) {
                        lower += nums[i]
                    }
                    for (i in idx + x until idx + 2 * x) {
                        higher += nums[i]
                    }
                    dp[idx][high] = higher - lower
                }

                val score = dp[idx][high] + solve(idx + 2 * x + 1, movesLeft - x)
                best = max(best, score)
            }
            dp2[idx][movesLeft] = best
        }
        return dp2[idx][movesLeft]
    }

    print(solve(0, k))
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