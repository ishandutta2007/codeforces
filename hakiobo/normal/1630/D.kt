import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max

fun main() {
    fun gcd(p: Int, q: Int): Int {
        return if (p < 0) gcd(-p, q)
        else if (q < 0) gcd(p, -q)
        else if (p == 0) q
        else if (q == 0) p
        else if (p and 1 == 0 && q and 1 == 0) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1 == 0) gcd(p shr 1, q)
        else if (q and 1 == 0) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val a = LongArray(n) { br.readInt().toLong() }
        var g = br.readInt()
        repeat(m - 1) {
            g = gcd(g, br.readInt())
        }
        val classes = Array(g) {
            mutableListOf<Long>()
        }
        for (x in 0 until n) {
            classes[x % g].add(a[x])
        }
        for (x in 0 until g) {
            classes[x].sortBy { it.absoluteValue }
        }
        var lastClasses = 0L
        var reverseLastClasses = 0L
        var ans = 0L
        for (rem in 0 until g) {
            for (x in classes[rem].lastIndex downTo 1) {
                ans += classes[rem][x].absoluteValue
                if (classes[rem][x] < 0) {
                    classes[rem][0] *= -1L
                }
            }
            lastClasses += classes[rem][0]
            reverseLastClasses -= classes[rem][0]
        }
        ans += max(lastClasses, reverseLastClasses)

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