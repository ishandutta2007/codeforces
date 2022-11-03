import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val matrix = Array(n) {
        IntArray(n) { br.readInt() }
    }
    var good = true
    for (i in 0 until n) {
        if (matrix[i][i] != 0) good = false
        for (j in i + 1 until n) {
            if (matrix[i][j] != matrix[j][i]) good = false
        }
    }
    if (good) {
        fun r(rows: List<Int>, cannotExceed: Int): Boolean {
            if (rows.size == 1) return true
            var high = 0
            for (row in rows) {
                high = max(matrix[rows.first()][row], high)
            }
            if (high > cannotExceed) return false
            val goodRows = mutableListOf<Int>()
            val badRows = mutableListOf<Int>()
            for (row in rows) {
                if (matrix[rows.first()][row] == high) {
                    goodRows += row
                } else {
                    badRows += row
                }
            }
            for (gRow in goodRows) {
                for (bRow in badRows) {
                    if (matrix[gRow][bRow] != high) return false
                }
            }
            if (badRows.size == 0) {
                for (i in goodRows.indices) {
                    for (j in i + 1 until goodRows.size) {
                        if (matrix[goodRows[i]][goodRows[j]] != 0) return false
                    }
                }
                return true
            } else {
                return r(goodRows, high) && r(badRows, high)
            }
        }
        good = r((0 until n).toList(), Int.MAX_VALUE)
    }
    if (good) {
        println("MAGIC")
    } else {
        println("NOT MAGIC")
    }
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