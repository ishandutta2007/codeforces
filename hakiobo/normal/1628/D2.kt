import java.io.BufferedReader

fun main() {
    val MAX_N = 1_000_000
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

    val fact = LongArray(MAX_N)
    fact[0] = 1L
    for (x in 1 until MAX_N) {
        fact[x] = (fact[x - 1] * x) % mod
    }
    val invFact = LongArray(MAX_N)
    invFact[MAX_N - 1] = modPow(fact.last(), mod - 2)
    for (x in MAX_N - 2 downTo 0) {
        invFact[x] = (invFact[x + 1] * (x + 1)) % mod
    }
    fun modChoose(n: Int, k: Int): Long {
        if (k > n || k < 0) return 0L
        val ret = (fact[n] * invFact[k]) % mod
        return (ret * invFact[n - k]) % mod
    }

    val invTwo = (mod + 1) shr 1

//    val dp = Array(2001) { turns -> LongArray(turns + 1) }
//    for (turnsLeft in 1..2000) {
//        for (plusesLeft in 1..turnsLeft) {
//            if (plusesLeft == turnsLeft) {
//                dp[turnsLeft][plusesLeft] = (dp[turnsLeft - 1][plusesLeft - 1] + 1) % mod
//            } else {
//                val numToUse =
//                    ((dp[turnsLeft - 1][plusesLeft] - dp[turnsLeft - 1][plusesLeft - 1] + mod) * invTwo) % mod
//                dp[turnsLeft][plusesLeft] = (dp[turnsLeft - 1][plusesLeft - 1] + numToUse) % mod
//            }
//        }
//    }


    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt().toLong()
        var movesMade = 0
        var plusesMade = 0
        var ans = 0L
        var tPow = 1L
        var curNum = 0L
        while (movesMade < n) {
            if (plusesMade < m) {
                curNum = if (curNum == 0L) {
                    1L
                } else {
                    (curNum shl 1) % mod
                }
                plusesMade++
                ans++
                if (ans >= mod) {
                    ans = 0L
                }
            } else {
                curNum = ((curNum shl 1) + mod - modChoose(movesMade - 1, plusesMade - 1)) % mod
                ans += mod - ((curNum * tPow) % mod)
                ans %= mod
            }


            movesMade++
            tPow = (tPow * invTwo) % mod
        }

        sb.appendLine((k * ans)%mod)

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