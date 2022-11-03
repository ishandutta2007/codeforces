import java.io.BufferedReader
import kotlin.math.min

fun main() {
    fun gcd(p: Long, q: Long): Long {
        return if (p == 0L) q
        else if (q == 0L) p
        else if (p and 1 == 0L && q and 1 == 0L) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1 == 0L) gcd(p shr 1, q)
        else if (q and 1 == 0L) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val m = br.readInt().toLong()
        val d = br.readInt().toLong()
        val w = br.readInt().toLong()
        val low = min(m, d)
        if (w == 1L || d == 1L) {
            sb.append((low * (low - 1)) shr 1).append('\n')
        } else {
            val gcd = w / gcd(w, d - 1)

            val type1 = low % gcd
            val type2 = gcd - type1

            val size2 = low / gcd
            val size1 = size2 + 1
            var ans = type2 * ((size2 * (size2 - 1)) / 2)
            ans += type1 * (size1 * (size1 - 1) / 2)
            sb.append(ans).append('\n')
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