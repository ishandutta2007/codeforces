import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = IntArray(n) { br.readInt() }


    val ranges = Array(n) { IntArray(n) }
    var ans = Int.MAX_VALUE
    val oCt = a.count { it == 1 }
    for (left in 0 until n) {
        ranges[left][left] = a[left]
        for (right in left + 1 until n) {
            ranges[left][right] = gcd(ranges[left][right - 1], a[right])
            if (ranges[left][right] == 1) {
                ans = min(ans, right - left + n - 1)
            }
        }
    }
    if (oCt != 0) {
        println(n - oCt)
    } else if (ranges[0][n - 1] == 1) {
        println(ans)
    } else {
        println(-1)
    }

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