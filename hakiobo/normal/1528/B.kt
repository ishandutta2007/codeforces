import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val sieve = IntArray(n + 1) { 1 }
    val mod = 998244353L
    for (x in 2..n) {
        if (sieve[x] == 1) {
            sieve[x] = x
            var i = x
            while (i <= n) {
                sieve[i] = x
                i += x
            }

        }
    }
    val dp1 = LongArray(n + 1) { x ->
        var i = x
        var numFactors = 1L
        if (x == 100) {
            i *= 1
        }
        while (sieve[i] != 1) {
            val check = sieve[i]
            var ct = 0
            while (sieve[i] == check) {
                i /= sieve[i]
                ct++
            }
            numFactors *= ct + 1
        }
        numFactors % mod
    }
    dp1[0] = 0
    val ans = LongArray(n + 1)

    var p = 0L
    for (x in 1..n) {
        ans[x] = (dp1[x] + p) % mod
        p += ans[x]
        p %= mod
    }

    print(ans.last())

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