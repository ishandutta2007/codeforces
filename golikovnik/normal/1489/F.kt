/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    val a = readLine()!!.split(" ").map { it.toInt() }
    val INF = m + 1
    val dp = Array(n + 1) { INF }
    dp[n] = 0
    var right = n - 1
    var sum = 0L
    var ans = 0
    for (left in n - 1 downTo 0) {
        while (sum + a[left] > k) {
            sum -= a[right--]
        }
        dp[left] = (dp[right + 1] + 1).also {
            if (it < INF) ans = n - left
        }
        sum += a[left]
    }
    println(ans)
}