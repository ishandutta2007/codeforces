import java.io.BufferedReader

fun main() {
    fun prefixFunction(s: String): IntArray {
        val pi = IntArray(s.length)
        for (i in 1 until s.length) {
            var j = pi[i - 1]
            while (j > 0 && s[i] != s[j]) j = pi[j - 1]
            if (s[i] == s[j]) j++
            pi[i] = j
        }
        return pi
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val k = br.readInt()
    val s = run {
        val s = br.readLine()
        val s2 = StringBuilder()
        for (x in 0 until k) {
            s2.append(s[x % n])
        }
        s2.toString()
    } 
    
    val p = prefixFunction(s)
    var limit = k
    for (x in p.indices) {
        if (s[p[x]] < s[(x + 1) % k]) {
            limit = x + 1 - p[x]
            break
        }
    }
    for (x in 0 until k) {
        sb.append(s[x % limit])
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