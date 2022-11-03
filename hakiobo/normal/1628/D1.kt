import java.io.BufferedReader

fun main() {
    val mod = 1_000_000_007L
    fun modPow(n: Long, k: Long): Long {
        if (k == 0L) {
            return 1L
        }
        var half = modPow(n, k shr 1)
        half *= half
        if (k and 1L == 1L) {
            half %= mod
            half *= n
        }
        return half % mod
    }
//    val fact = LongArray()
//    fun modChoose()

    val invTwo = (mod + 1) shr 1

    val dp = Array(2001) { turns -> LongArray(turns + 1) }
    for (turnsLeft in 1..2000) {
        for (plusesLeft in 1..turnsLeft) {
            if (plusesLeft == turnsLeft) {
                dp[turnsLeft][plusesLeft] = (dp[turnsLeft - 1][plusesLeft - 1] + 1) % mod
            } else {
                val numToUse = ((dp[turnsLeft - 1][plusesLeft] - dp[turnsLeft - 1][plusesLeft - 1] + mod) * invTwo) % mod
                dp[turnsLeft][plusesLeft] = (dp[turnsLeft - 1][plusesLeft - 1] + numToUse) % mod
            }
        }
    }


    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt().toLong()
        sb.appendLine((dp[n][m] * k) % mod)

    }
    println(sb)
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