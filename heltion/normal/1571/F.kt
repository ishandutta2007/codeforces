import kotlin.math.max

fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val (n, m) = readInts()
    val kt = Array(n){readInts()}
    val dp = Array(n + 1){BooleanArray(m / 2 + 2)}
    dp[0][0] = true
    var one = 0
    var two = 0
    for (i in 0 until n) {
        val (k, t) = kt[i]
        for (j in 0 .. m / 2 + 1) dp[i + 1][j] = dp[i][j]
        if (t == 1) one += k
        else {
            two += k
            if (k <= m / 2 + 1) for (j in k .. m / 2 + 1) if (dp[i][j - k]) dp[i + 1][j] = true
        }
    }
    var p = -1
    for (i in 0 .. m / 2 + 1) if (dp[n][i]) {
        val j = two - i
        if (i >= j && i * 2 - (if (i > j) 1 else 0) + one <= m)
            p = i
    }
    if (p == -1) println(p)
    else {
        val first = BooleanArray(n)
        for (i in n - 1 downTo 0) {
            val (k, t) = kt[i]
            if (t == 2 && p >= k && dp[i][p - k]) {
                p -= k
                first[i] = true
            }
        }
        var oneDay = 1
        var firstDay = one + 1
        var secondDay = one + 2
        for (i in 0 until n) {
            val (k, t) = kt[i]
            if (t == 1) {
                print("$oneDay ")
                oneDay += k
            }
            else if (first[i]) {
                print("$firstDay ")
                firstDay += k * 2
            }
            else {
                print("$secondDay ")
                secondDay += k * 2
            }
        }
    }
}