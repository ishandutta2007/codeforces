import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val r = br.readInt()
        val c = br.readInt()
        val grid = Array(r) { br.readLine().toCharArray() }
        var highSum = Int.MIN_VALUE
        var lowSum = Int.MAX_VALUE
        var highDif = Int.MIN_VALUE
        var lowDif = Int.MAX_VALUE
        for (row in 0 until r) {
            for (col in 0 until c) {
                if (grid[row][col] == 'B') {
                    highSum = max(highSum, row + col)
                    lowSum = min(lowSum, row + col)
                    highDif = max(highDif, row - col)
                    lowDif = min(lowDif, row - col)
                }
            }
        }
        var lowDist = Int.MAX_VALUE
        var ansRow = -1
        var ansCol = -1
        for (row in 0 until r) {
            for (col in 0 until c) {
                val dist = max(
                    max(
                        (row + col - highSum).absoluteValue,
                        (row + col - lowSum).absoluteValue
                    ),
                    max(
                        (row - col - lowDif).absoluteValue,
                        (row - col - highDif).absoluteValue
                    )
                )
                if (dist < lowDist) {
                    lowDist = dist
                    ansRow = row
                    ansCol = col
                }
            }
        }
        bw.appendLine("${ansRow + 1} ${ansCol + 1}")
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