import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val h = br.readInt()
    val m = br.readInt()
    val heights = IntArray(n) { h }
    repeat(m) {
        val l = br.readInt() - 1
        val r = br.readInt() - 1
        val hi = br.readInt()
        for (x in l..r) {
            heights[x] = min(hi, heights[x])
        }
    }
    var ans = 0
    for (x in 0 until n) {
        ans += heights[x] * heights[x]
    }
    print(ans)
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