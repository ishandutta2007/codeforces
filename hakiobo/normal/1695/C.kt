import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val grid = Array(n) { IntArray(m) { br.readInt() } }
        if ((n + m) and 1 == 0) {
            bw.appendLine("NO")
        } else {
            val dpMin = Array(n) { row -> IntArray(m) { col -> grid[row][col] } }
            val dpMax = Array(n) { row -> IntArray(m) { col -> grid[row][col] } }
            for (col in 1 until m) {
                dpMax[0][col] += dpMax[0][col - 1]
                dpMin[0][col] += dpMin[0][col - 1]
            }
            for (row in 1 until n) {
                dpMin[row][0] += dpMin[row - 1][0]
                dpMax[row][0] += dpMax[row - 1][0]
                for (col in 1 until m) {
                    dpMin[row][col] += min(dpMin[row - 1][col], dpMin[row][col - 1])
                    dpMax[row][col] += max(dpMax[row - 1][col], dpMax[row][col - 1])
                }
            }
            if (dpMax.last().last() >= 0 && dpMin.last().last() <= 0) {
                bw.appendLine("YES")
            } else {
                bw.appendLine("NO")
            }
        }
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