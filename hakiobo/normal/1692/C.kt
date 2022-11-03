import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        br.read()
        br.read()
        val grid = Array(8) {
            val row = CharArray(8) { br.read().toChar() }
            br.read()
            br.read()
            row
        }


        for (row in 0 until 8) {
            if (grid[row].count { it == '#' } == 2) {
                var left = 8
                var right = -1
                for (col in 0 until 8) {
                    if (grid[row][col] == '#') {
                        left = min(left, col)
                        right = max(right, col)
                    }
                }
                val ansRow = ((right - left) shr 1) + row + 1
                val ansCol = ((right + left) shr 1) + 1
                bw.appendLine("$ansRow $ansCol")
                break
            }
        }
    }
    bw.flush()
}