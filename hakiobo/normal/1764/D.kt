import java.io.BufferedReader

fun main() {

    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val p = br.readInt().toLong()
    val fact = LongArray(n + 1)
    fact[0] = 1
    for (i in 1..n) {
        fact[i] = (i * fact[i - 1]) % p
    }
    val invFacts = LongArray(n + 1)
    val inv = LongArray(n + 1)
    for (i in 1..n) {
        inv[i] = modPow(i.toLong(), p - 2, p)
    }
    invFacts[n] = modPow(fact.last(), p - 2L, p)
    for (i in n downTo 1) {
        invFacts[i - 1] = (invFacts[i] * i) % p
    }
    fun choose(nArg: Int, k: Int): Long {
        val denom = (invFacts[nArg - k] * invFacts[k]) % p
        return (denom * fact[nArg]) % p
    }

    val ways = Array(n + 1) { LongArray(n + 1) }
    val prefixes = LongArray(n + 1)
    val hop = n / 2
    ways[0][0] = 1L
    ways[0][1] = p - 1
    for (i in 0 until n) {
        for (jumps in 0..i) {
            prefixes[jumps] = (prefixes[jumps] + ways[jumps][i]) % p
            ways[jumps + 1][i + 1] = ways[jumps + 1][i + 1] + prefixes[jumps]
            if (i + 1 + hop <= n) {
                ways[jumps + 1][i + 1 + hop] = (ways[jumps + 1][i + 1 + hop] + p - prefixes[jumps]) % p
            }
        }
    }
    for (j in 0..n) {
        prefixes[j] = (prefixes[j] + ways[j][n]) % p
        if (prefixes[j] != 0L) {
            prefixes[j] = (prefixes[j] * n) % p
            prefixes[j] = (prefixes[j] * inv[j]) % p
        }
    }
    var ans = 0L
    for (i in n downTo 1) {
        val potentialChoices = (prefixes[i] * i) % p
        val aliveChoices = (prefixes[i - 1] * (n - (i - 1))) % p
        val dif = (potentialChoices - aliveChoices + p) % p

        val added = (dif * fact[n - i]) % p
        ans = (ans + added) % p
    }
    println(ans)


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