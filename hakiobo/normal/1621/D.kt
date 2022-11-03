import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val off = arrayOf(0, n - 1)
        val off2 = arrayOf(0, n)
        val grid = Array(n shl 1) { LongArray(n shl 1) { br.readInt().toLong() } }
        var ans = 0L
        for (row in n until (n shl 1)) {
            for (col in n until (n shl 1)) {
                ans += grid[row][col]
                grid[row][col] = 0L
            }
        }
        var other = Long.MAX_VALUE
        for (x in 0 until 2) {
            for (y in 0 until 4) {
                other = min(other, grid[off2[x] + off[y and 1]][off2[x xor 1] + off[y shr 1]])
            }
        }
        sb.appendLine(other + ans)
    }
    println(sb)
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