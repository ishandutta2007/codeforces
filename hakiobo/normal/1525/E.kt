import java.io.BufferedReader
import kotlin.math.max

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

    val mod = 998244353L
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val factorial = LongArray(n + 1)
    factorial[0] = 1L
    for (x in 1..n) {
        factorial[x] = (factorial[x - 1] * x) % mod
    }
    val invFactorial = modPow(factorial.last(), (mod - 2).toInt(), mod)
    val powers = Array(n) { IntArray(m) { br.readInt() - 1 } }

    var ans = 0L
    repeat(m) { idx ->
        val cts = IntArray(n + 1)
        for (x in 0 until n) {
            cts[powers[x][idx]]++
        }
        var num = 1L
        var ct = 0
        for (x in n downTo 1) {
            ct += cts[x]
            num *= ct
            ct--
            num %= mod
        }
        num *= -1
        num += mod
        num += factorial.last()
        num %= mod
        num *= invFactorial
        num %= mod
        ans += num
        ans %= mod
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