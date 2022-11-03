import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    val dRow = intArrayOf(0, 1, 0, -1)
    val dCol = intArrayOf(1, 0, -1, 0)
    repeat(t) {
        val n = br.readInt()
        val xors = Array(n) { IntArray(n) { br.readInt() } }
        var ans = 0
        val used = Array(n) { BooleanArray(n) }
        fun use(row: Int, col: Int) {
            val mirrorCol = n - 1 - col
            for (dir in 0 until 4) {
                val newRow = row + dRow[dir]
                val newCol = col + dCol[dir]
                if (newRow in 0 until n && newCol in 0 until n) {
                    used[newRow][newCol] = true
                }
            }
            ans = ans xor xors[row][col] xor xors[row][mirrorCol]
        }
        use(0, 0)
        for (col in 1 until n - 1 step 2) {
            if (!used[0][col]) {
                use(0, col + 1)
            }
        }
        for (row in 0 until n - 1) {
            for (col in ((row and 1) xor 1) until n step 2) {
                if (!used[row][col]) {
                    use(row + 1, col)
                }
            }
        }
        sb.appendLine(ans)
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