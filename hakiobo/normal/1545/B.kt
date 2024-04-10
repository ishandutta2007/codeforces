import java.io.BufferedReader

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

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    val mod = 998_244_353L
    val limit = 100_000
    val factorials = LongArray(limit + 1)
    factorials[0] = 1L
    for (x in 1 until factorials.size) {
        factorials[x] = (x * factorials[x - 1]) % mod
    }
    val invFactorials = LongArray(limit + 1)
    invFactorials[limit] = modPow(factorials[limit], (mod - 2).toInt(), mod)
    for (x in limit - 1 downTo 0) {
        invFactorials[x] = ((x + 1) * invFactorials[x + 1]) % mod
    }

    repeat(t) {
        val n = br.readInt()
        val num = br.readLine()
        var pairs = 0
        var numSingles = 0
        var idx = 0
        while (idx < n) {
            if (num[idx] == '1') {
                if (idx + 1 < n && num[idx + 1] == '1') {
                    pairs++
                    idx++
                } else {
                    numSingles++
                }
            }
            idx++
        }
        val chooseTop = n - pairs - numSingles
        var ans = factorials[chooseTop] * invFactorials[pairs]
        ans %= mod
        ans *= invFactorials[chooseTop - pairs]
        ans %= mod
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