import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val grid = Array(n) { IntArray(m) { br.readInt() } }
        val sorted = Array(n) { row ->
            grid[row].sorted().toIntArray()
        }
        val needsSwap = BooleanArray(m)
        for (row in 0 until n) {
            for (col in 0 until m) {
                if (grid[row][col] != sorted[row][col]) {
                    needsSwap[col] = true
                }
            }
        }
        var ct = 0
        var low = -1
        var high = -1
        for (col in 0 until m) {
            if (needsSwap[col]) {
                ct++
                if (ct == 1) {
                    low = col
                } else {
                    high = col
                }
            }
        }
        when (ct) {
            0 -> bw.appendLine("1 1")
            2 -> {
                var good = true
                for (row in 0 until n) {
                    if (grid[row][low] != sorted[row][high] || grid[row][high] != sorted[row][low]) good = false
                }
                if (good) {
                    bw.appendLine("${low + 1} ${high + 1}")
                } else {
                    bw.appendLine("-1")
                }
            }
            else -> bw.appendLine("-1")
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