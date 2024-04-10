import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).sorted().toIntArray()
    var dp = Array(2) { Array(k + 1) { IntArray(k + 1) { Int.MIN_VALUE } } }
    dp[0][0][0] = 0
    var t = 0
    for (x in a) {
        for (i in 0..k) {
            for (j in 0..k) {
                dp[1 - t][i][j] = Int.MIN_VALUE
            }
        }
        for (i in 0..k) {
            for (j in 0..k) {
                if (dp[t][i][j] == Int.MIN_VALUE) {
                    continue
                }
                if (i < k && j < k) {
                    dp[1 - t][i + 1][j + 1] = max(dp[1 - t][i + 1][j + 1], dp[t][i][j] - x)
                }
                if (j > 0) {
                    dp[1 - t][i][j - 1] = max(dp[1 - t][i][j - 1], dp[t][i][j] + x)
                }
                if (j == 0) {
                    dp[1 - t][i][j] = max(dp[1 - t][i][j], dp[t][i][j])
                }
            }
        }
        t = 1 - t
    }
    println(dp[t][k][0])
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}