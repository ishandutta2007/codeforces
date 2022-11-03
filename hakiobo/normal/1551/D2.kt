import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    val chars = CharArray(26) { 'a' + it }
    fun getChar(row: Int, col: Int): Char {
        return chars[(row * 3 + col) % 26]
    }

    fun buildGrid(sRow: Int, sCol: Int, horizontalNeeded: Int, grid: Array<CharArray>, n: Int, m: Int) {
        var toPlace = horizontalNeeded
        for (row in sRow until n step 2) {
            for (col in sCol until m step 2) {
                if (toPlace > 0) {
                    toPlace -= 2
                    val c1 = getChar(row, col)
                    val c2 = getChar(row + 1, col)
                    grid[row][col] = c1
                    grid[row][col + 1] = c1
                    grid[row + 1][col] = c2
                    grid[row + 1][col + 1] = c2
                } else {
                    val c1 = getChar(row, col)
                    val c2 = getChar(row, col + 1)
                    grid[row][col] = c1
                    grid[row + 1][col] = c1
                    grid[row][col + 1] = c2
                    grid[row + 1][col + 1] = c2
                }
            }
        }
    }
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val k = br.readInt()
        val k2 = ((n * m) shr 1) - k
        if (n and 1 == 1) {
            val neededHorizontal = m shr 1
            if (neededHorizontal > k) {
                sb.appendLine("NO")
            } else if (k2 and 1 == 1) {
                sb.appendLine("NO")
            } else {
                sb.appendLine("YES")
                val grid = Array(n) { CharArray(m) }
                var toPlace = k
                for (col in 0 until m step 2) {
                    val c = getChar(0, col)
                    grid[0][col] = c
                    grid[0][col + 1] = c
                    toPlace--
                }
                buildGrid(1, 0, toPlace, grid, n, m)
                sb.appendLine(grid.joinToString("\n") { it.joinToString("") })
            }
        } else if (k and 1 == 1) {
            sb.appendLine("NO")
        } else if (m and 1 == 1) {
            val neededVertical = n shr 1
            if (neededVertical > k2) {
                sb.appendLine("NO")
            } else {
                sb.appendLine("YES")
                val grid = Array(n) { CharArray(m) }
                for (row in 0 until n step 2) {
                    val c = getChar(row, 0)
                    grid[row][0] = c
                    grid[row + 1][0] = c
                }
                buildGrid(0, 1, k, grid, n, m)

                sb.appendLine(grid.joinToString("\n") { it.joinToString("") })
            }
        } else {
            sb.appendLine("YES")
            val grid = Array(n) { CharArray(m) { '0' } }
            buildGrid(0, 0, k, grid, n, m)
            sb.appendLine(grid.joinToString("\n") { it.joinToString("") })
        }
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