import java.io.BufferedReader
import kotlin.math.max

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
    val q = br.readInt()
    repeat(q) {
        val s = br.readLine()
        val t = br.readLine()
        val pi1 = prefixFunction("$t#${t.reversed()}$$s")
        val pi2 = prefixFunction("${t.reversed()}#$t$$s")
        val n = t.length
        val m = s.length
        var c1 = pi1[n shl 1]
        var c2 = pi2[n shl 1]
        while (c1 and 1 == 0) {
            c1 = pi1[c1 - 1]
        }
        while (c2 and 1 == 0) {
            c2 = pi2[c2 - 1]
        }

        c1 = (n - c1) + ((c1 + 1) shr 1)
        c2 = (n - c2) + ((c2 + 1) shr 1)

        var good = false
        for (x in 0 until m) {
            val idx = (n shl 1) + 2 + x
            if (pi1[idx] == c2) good = true
            if (pi2[idx] == c1) good = true
        }
        if (good) {
            sb.appendLine("YES")
        } else {
            sb.appendLine("NO")
        }


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