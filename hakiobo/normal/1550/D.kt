import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    fun modPow(n: Long, k: Int, m: Long): Long {
        if (k == 0) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1) {
            half %= m
            half *= n
        }
        return half % m
    }

    val mod = 1_000_000_007L
    val limit = 200_000
    val factorial = LongArray(limit + 1)
    factorial[0] = 1L
    for (x in 1..limit) {
        factorial[x] = (x * factorial[x - 1]) % mod
    }
    val invFactorial = LongArray(limit + 1)
    invFactorial[limit] = modPow(factorial[limit], (mod - 2).toInt(), mod)
    for (x in limit downTo 1) {
        invFactorial[x - 1] = (invFactorial[x] * x) % mod
    }
    fun choose(n: Int, k: Int, m: Long): Long {
        var ret = factorial[n] * invFactorial[k]
        ret %= m
        ret *= invFactorial[n - k]
        return ret % m
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val l = br.readInt()
        val r = br.readInt()
        val lowSpace = 1 - l
        val highSpace = r - n
        var ans = 0L
        var dif = min(lowSpace, highSpace)
        if (n and 1 == 0) {
            val waysToSplit = choose(n, n shr 1, mod)
            ans += dif * waysToSplit
            ans %= mod
            dif++
            while ((n shr 1) + dif <= r && (n shr 1) + 1 - dif >= l) {
                val mustSubtract = max(n - (r - dif), 0)
                val mustAdd = max(dif + l - 1, 0)
                ans += choose(n - mustSubtract - mustAdd, (n shr 1) - mustSubtract, mod)
                ans %= mod
                dif++
            }
        } else {
            val largeGroup = (n + 1) shr 1
            val smallGroup = n shr 1
            val waysToSplit = choose(n, largeGroup, mod)
            ans += dif * 2 * waysToSplit
            ans %= mod
            dif++
            //first condition is if smaller group cn be adding
            //second condition is if smaller group can be subtracting
            while (smallGroup + dif <= r && largeGroup + 1 - dif >= l) {
                val mustSubtract = max(n - (r - dif), 0)
                val mustAdd = max(dif + l - 1, 0)
                if (largeGroup + dif <= r) { // add is bigger group
                    ans += choose(n - mustSubtract - mustAdd, largeGroup - mustAdd, mod)
                    ans %= mod
                }
                if (smallGroup + 1 - dif >= l) { //subtract is bigger group
                    ans += choose(n - mustSubtract - mustAdd, largeGroup - mustSubtract, mod)
                    ans %= mod
                }
                dif++
            }
        }
        sb.appendLine(ans)
    }
    print(sb)
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