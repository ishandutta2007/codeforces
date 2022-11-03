import java.io.BufferedReader
import java.util.*
import kotlin.math.min
 
fun main() {
    val dRow = listOf(0, 1, 0, -1)
    val dCol = listOf(1, 0, -1, 0)
 
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val w = br.readInt().toLong()
    val grid = Array(n) {
        IntArray(m) {
            br.readInt()
        }
    }
    val distFromStart = Array(n) { LongArray(m) { Long.MAX_VALUE } }
    var bestStartPortal = Long.MAX_VALUE
 
 
    val visitedFromStart = Array(n) { BooleanArray(m) }
    val queue = ArrayDeque<Pair<Int, Int>>()
    distFromStart[0][0] = 0L
    queue += 0 to 0
    visitedFromStart[0][0] = true
    while (queue.isNotEmpty()) {
        val (row, col) = queue.poll()
        if (grid[row][col] > 0) {
            if (distFromStart[row][col] + grid[row][col] < bestStartPortal) {
                bestStartPortal = distFromStart[row][col] + grid[row][col]
            }
        }
        for (dir in 0 until 4) {
            val newRow = row + dRow[dir]
            val newCol = col + dCol[dir]
            if (newRow in 0 until n && newCol in 0 until m && grid[newRow][newCol] != -1) {
                if (!visitedFromStart[newRow][newCol]) {
                    distFromStart[newRow][newCol] = distFromStart[row][col] + w
                    visitedFromStart[newRow][newCol] = true
                    queue += newRow to newCol
                }
            }
        }
    }
 
 
    val distsToEnd = Array(n) { LongArray(m) { Long.MAX_VALUE } }
    var bestEndPortal = Long.MAX_VALUE
 
 
    val visitedFromEnd = Array(n) { BooleanArray(m) }
    queue.clear()
    distsToEnd[n - 1][m - 1] = 0L
    queue += n - 1 to m - 1
    visitedFromEnd[n - 1][m - 1] = true
    while (queue.isNotEmpty()) {
        val (row, col) = queue.poll()
        if (grid[row][col] > 0) {
            if (distsToEnd[row][col] + grid[row][col] < bestEndPortal) {
                bestEndPortal = distsToEnd[row][col] + grid[row][col]
            }
        }
        for (dir in 0 until 4) {
            val newRow = row + dRow[dir]
            val newCol = col + dCol[dir]
            if (newRow in 0 until n && newCol in 0 until m && grid[newRow][newCol] != -1) {
                if (!visitedFromEnd[newRow][newCol]) {
                    distsToEnd[newRow][newCol] = distsToEnd[row][col] + w
                    visitedFromEnd[newRow][newCol] = true
                    queue += newRow to newCol
                }
            }
        }
    }
    if (distsToEnd[0][0] == Long.MAX_VALUE && (bestStartPortal == Long.MAX_VALUE || bestEndPortal == Long.MAX_VALUE)) {
        print(-1)
    } else if (bestStartPortal == Long.MAX_VALUE || bestEndPortal == Long.MAX_VALUE) {
        print(distsToEnd[0][0])
    } else {
        print(min(distsToEnd[0][0], bestEndPortal + bestStartPortal))
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