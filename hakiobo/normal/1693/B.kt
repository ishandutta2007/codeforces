import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val parents = IntArray(n)
        parents[0] = -1
        for (node in 1 until n) {
            parents[node] = br.readInt() - 1
        }
        val lefts = LongArray(n)
        val rights = LongArray(n)
        for (i in 0 until n) {
            lefts[i] = br.readInt().toLong()
            rights[i] = br.readInt().toLong()
        }
        val curValues = LongArray(n)
        var numMoves = 0
        for (node in n - 1 downTo 0) {
            curValues[node] = min(curValues[node], rights[node])
            if (curValues[node] < lefts[node]) {
                numMoves++
                curValues[node] = rights[node]
            }
            if (node != 0) {
                curValues[parents[node]] += curValues[node]
            }
        }
        bw.appendLine("$numMoves")
    }
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