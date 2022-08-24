import kotlin.math.*

const val mod = 1_000_000_007

fun solve() {
    val (n, p) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val s = a.toSet()
    fun isNew(x: Int): Boolean {
        var y = x
        while (y > 0) {
            if (y % 2 == 1) {
                y /= 2
            } else if (y % 4 == 0) {
                y /= 4
            } else {
                return true
            }
            if (s.contains(y)) {
                return false
            }
        }
        return true
    }
    var ptr = 0
    val dp = MutableList<Long>(p + 1) { 0L }
    for (i in 1..p) {
        dp[i] = dp[i - 1]
        if (i > 1) {
            dp[i] += dp[i - 2]
        }
        while (ptr < n && a[ptr] < (1 shl i)) {
            if (isNew(a[ptr])) {
                dp[i] += 1L
            }
            ptr += 1
        }
        dp[i] = dp[i] % mod
    }
    println(dp.sum() % mod)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}