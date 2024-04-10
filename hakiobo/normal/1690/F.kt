import java.io.BufferedReader

private fun prefixFunction(s: CharSequence): IntArray {
    val pi = IntArray(s.length)
    for (i in 1 until s.length) {
        var j = pi[i - 1]
        while (j > 0 && s[i] != s[j]) j = pi[j - 1]
        if (s[i] == s[j]) j++
        pi[i] = j
    }
    return pi
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine()
        val perm = IntArray(n) { br.readInt() - 1 }
        val seen = BooleanArray(n)
        var ans = 1L
        for (i in 0 until n) {
            val sb = StringBuilder()
            if (!seen[i]) {
                var len = 0
                var cur = i
                while (!seen[cur]) {
                    sb.append(s[cur])
                    seen[cur] = true
                    cur = perm[cur]
                    len++
                }
                val pi = prefixFunction(sb)
                if (len % (len - pi.last()) == 0) {
                    len -= pi.last()
                }
                val g = gcd(len.toLong(), ans)
                ans = (ans / g) * len
            }
        }
        bw.appendLine("$ans")
    }
    bw.flush()
}

private fun gcd(p: Long, q: Long): Long {
    return if (p < 0) gcd(-p, q)
    else if (q < 0) gcd(p, -q)
    else if (p == 0L) q
    else if (q == 0L) p
    else if (p and 1L == 0L && q and 1L == 0L) gcd(p shr 1, q shr 1) shl 1
    else if (p and 1L == 0L) gcd(p shr 1, q)
    else if (q and 1L == 0L) gcd(p, q shr 1)
    else if (p > q) gcd((p - q) shr 1, q)
    else gcd(p, (q - p) shr 1)
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