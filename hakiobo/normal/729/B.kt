import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val grid = Array(n) { IntArray(m) { br.readInt() } }

    val rowPrefix = Array(n) { IntArray(m + 1) }
    val colPrefix = Array(m) { IntArray(n + 1) }
    for (row in 0 until n) {
        rowPrefix[row][0] = 0
        for (col in 1..m) {
            rowPrefix[row][col] = rowPrefix[row][col - 1] + grid[row][col - 1]
        }
    }
    for (col in 0 until m) {
        colPrefix[col][0] = 0
        for (row in 1..n) {
            colPrefix[col][row] = colPrefix[col][row - 1] + grid[row - 1][col]
        }
    }
    var ans = 0
    for (row in 0 until n) {
        for (col in 0 until m) {
            if (grid[row][col] == 1) continue
            if (colPrefix[col][row] > 0) ans++
            if (colPrefix[col][n] > colPrefix[col][row]) ans++
            if (rowPrefix[row][col] > 0) ans++
            if (rowPrefix[row][m] > rowPrefix[row][col]) ans++

        }
    }
    println(ans)

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