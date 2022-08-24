import kotlin.math.*

data class State(var lastUpIfDown: Int, var lastDownIfUp: Int, var idxIfDown: Int, var idxIfUp: Int)

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val dp = MutableList(n) { State(Int.MIN_VALUE, Int.MAX_VALUE, -1, -1) }
    for (i in 1 until n) {
        dp[i] = State(Int.MAX_VALUE, Int.MIN_VALUE, -2, -2)
        if (a[i] < a[i - 1] && dp[i - 1].idxIfDown > -2 && dp[i - 1].lastUpIfDown < dp[i].lastUpIfDown) {
            dp[i].idxIfDown = dp[i - 1].idxIfDown
            dp[i].lastUpIfDown = dp[i - 1].lastUpIfDown
        }
        if (a[i] > a[i - 1] && dp[i - 1].idxIfUp > -2 && dp[i - 1].lastDownIfUp > dp[i].lastDownIfUp) {
            dp[i].idxIfUp = dp[i - 1].idxIfUp
            dp[i].lastDownIfUp = dp[i - 1].lastDownIfUp
        }
        if (dp[i - 1].idxIfUp > -2 && a[i] < dp[i - 1].lastDownIfUp && a[i - 1] < dp[i].lastUpIfDown) {
            dp[i].idxIfDown = i - 1
            dp[i].lastUpIfDown = a[i - 1]
        }
        if (dp[i - 1].idxIfDown > -2 && a[i] > dp[i - 1].lastUpIfDown && a[i - 1] > dp[i].lastDownIfUp) {
            dp[i].idxIfUp = i - 1
            dp[i].lastDownIfUp = a[i - 1]
        }
    }
    if (dp[n - 1].idxIfDown == -2 && dp[n - 1].idxIfUp == -2) {
        println("NO")
        return
    }
    println("YES")
    var cur = n - 1
    var up = dp[cur].idxIfUp > -2
    val ans = MutableList(n) { 0 }
    while (cur >= 0) {
        if (up) {
            val i = dp[cur].idxIfUp
            while (cur > i) {
                ans[cur] = 0
                cur -= 1
            }
            up = false
        } else {
            val i = dp[cur].idxIfDown
            while (cur > i) {
                ans[cur] = 1
                cur -= 1
            }
            up = true
        }
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}