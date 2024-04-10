import java.io.BufferedReader
import kotlin.math.min

fun main() {
    fun modPow(n: Long, k: Int, mod: Long): Long {
        if (k == 0) {
            return 1L
        }
        var half = modPow(n, k shr 1, mod)
        half *= half
        if (k and 1 == 1) {
            half %= mod
            half *= n
        }
        return half % mod
    }


    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt().toLong()

    val factorials = LongArray(n + 1) { 1L }
    for (x in 1..n) {
        factorials[x] = (x * factorials[x - 1]) % m
    }
    val inverseFactorials = LongArray(n + 1) { modPow(factorials[it], (m - 2L).toInt(), m) }
    fun bimnom(nC: Int, kC: Int, mod: Long): Long {
        var res = factorials[nC]
        res *= inverseFactorials[kC]
        res %= mod
        res *= inverseFactorials[nC - kC]
        return res % mod
    }


    val dp2 = LongArray(n) { modPow(2L, it, m) } //how many ways to manually turn on i + 1 computers in a row manually

    val dp = Array(n + 1) { LongArray(n + 1) }
    dp[0][0] = 1L
    for (i in 1..n) { // through the first i computers
        dp[i][i] = dp2[i - 1]
        for (j in (i - 1) downTo 0) { //with turning on j computers manually
            for (k in 1..min(j, i - 2)) {
                var l = (dp[i - k - 1][j - k] * dp2[k - 1]) % m
                l *= bimnom(j, k, m)
                l %= m
                dp[i][j] += l
                dp[i][j] %= m
            }
        }
    }
    var ans = 0L
    for (x in 1..n) {
        ans += dp[n][x]
        ans %= m
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