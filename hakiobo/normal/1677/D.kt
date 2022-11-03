import java.io.BufferedReader

private const val MOD = 998_244_353L
private const val MAX_N = 1_000_000
fun main() {
    val facts = LongArray(MAX_N + 1)
    facts[0] = 1L
    for (i in 1..MAX_N) {
        facts[i] = (i * facts[i - 1]) % MOD
    }
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()

        val v = IntArray(n) { br.readInt() }
        var bad = false
        for (i in n - k until n) {
            if (v[i] > 0) bad = true
        }

        if (bad) {
            bw.appendLine("0")
        } else {
            var ans = facts[k]
            for (i in 0 until n - k) {
                if (v[i] == -1) {
                    ans *= k + i + 1
                    ans %= MOD
                } else if (v[i] == 0) {
                    ans *= k + 1
                    ans %= MOD
                }
            }

            bw.appendLine("$ans")
        }
    }
    bw.flush()
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