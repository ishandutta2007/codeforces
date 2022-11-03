import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val b = IntArray(n) { br.readInt() }

        var bestVal = -1
        var bestRes = intArrayOf()

        for (rot in 0 until n) {
            var score = Int.MAX_VALUE
            val pairing = IntArray(n)
            for (x in 0 until n) {
                pairing[x] = 1 + (x + rot) % n
                score = min(score, (a[x] - b[(x + rot) % n]).absoluteValue)
            }
            if (score > bestVal) {
                bestVal = score
                bestRes = pairing
            }
        }
        sb.append(bestRes.joinToString(" ")).append("\n")
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