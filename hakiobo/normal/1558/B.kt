import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val mod = br.readInt().toLong()
    val reversePrefix = LongArray(n + 2)
    reversePrefix[n] = 1L
    for (x in n - 1 downTo 1) {
        reversePrefix[x] = reversePrefix[x + 1] shl 1

        var f = 2
        while (f * x <= n) {
            val low = f * x
            val high = f * (x + 1)
            reversePrefix[x] += reversePrefix[low] - reversePrefix[min(high, n + 1)] + mod
            f++
        }
        reversePrefix[x] %= mod
    }
    println((reversePrefix[1] + mod - reversePrefix[2]) % mod)
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