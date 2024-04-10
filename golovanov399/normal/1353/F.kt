import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var a = Array<LongArray>(n) { longArrayOf() }
    for (i in 0 until n) {
        a[i] = readLine()!!.split(' ').mapIndexed { j, x -> x.toLong() - i - j }.toLongArray()
    }
    var dp = Array<LongArray>(n + 1) { LongArray(m + 1) {-1} }
    dp[0][1] = 0
    var ans: Long = 1e18.roundToLong()
    for (vx in 0 until n) {
        for (vy in 0 until m) {
            val v = a[vx][vy]
            for (i in 0 until n) {
                for (j in 0 until m) {
                    if (a[i][j] < v) {
                        dp[i + 1][j + 1] = -1
                        continue
                    }
                    if (dp[i][j + 1] == -1L && dp[i + 1][j] == -1L) {
                        dp[i + 1][j + 1] = -1
                        continue
                    }
                    dp[i + 1][j + 1] = a[i][j] - v
                    if (dp[i][j + 1] > -1 && dp[i + 1][j] > -1) {
                        dp[i + 1][j + 1] += min(dp[i][j + 1], dp[i + 1][j])
                        continue
                    }
                    if (dp[i][j + 1] > -1) {
                        dp[i + 1][j + 1] += dp[i][j + 1]
                    }
                    if (dp[i + 1][j] > -1) {
                        dp[i + 1][j + 1] += dp[i + 1][j]
                    }
                }
            }
            if (dp[n][m] > -1) {
                ans = min(ans, dp[n][m])
            }
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}