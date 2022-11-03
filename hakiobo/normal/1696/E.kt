import java.io.BufferedReader

fun main() {
    val limit = 500_000
    val mod = 1_000_000_007L
    val facts = LongArray(limit + 1)
    val invFacts = LongArray(limit + 1)
    facts[0] = 1L
    for (i in 1..limit) {
        facts[i] = (i * facts[i - 1]) % mod
    }

    invFacts[limit] = modPow(facts[limit], mod - 2, mod)
    for (i in limit downTo 1) {
        invFacts[i - 1] = (i * invFacts[i]) % mod
    }
    fun choose(n: Int, k: Int): Long {
        val ans = (facts[n] * invFacts[k]) % mod

        return (ans * invFacts[n - k]) % mod
    }

    val br = System.`in`.bufferedReader()
    val n = br.readInt() + 1


    val a = IntArray(n) { br.readInt() }
    var ans = 0L
    for (i in 0 until n) {
        if (a[i] != 0) {
            ans += choose(a[i] + i, i + 1)
        }
    }
    println(ans % mod)
}

private fun modPow(n: Long, k: Long, m: Long): Long {
    if (k == 0L) {
        return 1L
    }
    var half = modPow(n, k shr 1, m)
    half *= half
    if (k and 1L == 1L) {
        half %= m
        half *= n
    }
    return half % m
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