import java.io.BufferedReader
import java.util.*
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        var ans = 0
        for (base in 0..(n shr 1)) {
            val remapped = IntArray(n) { idx -> a[idx] - a[base] }
            val sets = Array(n shr 1) { TreeSet<Int>() }
            sets[0].add(0)
            for (x in base + 1 until n) {
                for (y in sets.lastIndex downTo 1) {
                    for (z in sets[y - 1]) {
                        sets[y].add(gcd(z, remapped[x]))
                    }
                }
            }
            ans = if (0 in sets.last()) {
                Int.MAX_VALUE
            } else {
                max(ans, sets.last().last()!!)
            }
        }
        sb.appendLine(if (ans == Int.MAX_VALUE) -1 else ans)

    }
    println(sb)
}

private fun gcd(p: Int, q: Int): Int {
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