import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val a = IntArray(n) { br.readInt() }
    var best = Long.MAX_VALUE
    for (i in 0 until n) {
        var moves = 0L
        var cur = 0L
        for (j in i + 1 until n) {
            val toMove = 1 + cur / a[j]
            moves += toMove
            cur = toMove * a[j]
        }
        cur = 0L
        for (j in i - 1 downTo 0) {
            val toMove = 1 + cur / a[j]
            moves += toMove
            cur = toMove * a[j]
        }
        best = min(best, moves)
    }
    bw.append(best.toString())
    bw.flush()
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