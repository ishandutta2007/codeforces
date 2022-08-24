import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    var dp = IntArray(n + 1) {0}
    for (i in a.indices) {
        dp[i + 1] = dp[i]
        if (a[i] <= i + 1) {
            dp[i + 1] = max(dp[i + 1], dp[i - a[i] + 1] + 1)
        }
    }
    println(dp[n])
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}