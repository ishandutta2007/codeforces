import java.io.BufferedReader
import java.util.*
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val rows = br.readInt()
        val cols = br.readInt()
        val grid = Array(rows) {
            br.readLine().toCharArray()
        }
        var goodCount = 0
        var valid = true
        for (row in 0 until rows) {
            for (col in 0 until cols) {
                if (grid[row][col] == 'B') {
                    for (i in 1..4) {
                        val (adjRow, adjCol) = when (i) {
                            1 -> Pair(row - 1, col)
                            2 -> Pair(row + 1, col)
                            3 -> Pair(row, col - 1)
                            4 -> Pair(row, col + 1)
                            else -> Pair(-1, -1)
                        }
                        if (adjCol in 0 until cols && adjRow in 0 until rows) {
                            val c = grid[adjRow][adjCol]
                            when (c) {
                                '.' -> grid[adjRow][adjCol] = '#'
                                'G' -> valid = false
                            }
                        }
                    }

                } else if (grid[row][col] == 'G') {
                    goodCount++
                }
            }
        }
        if (valid && grid.last().last() == '.') {
            val queue: Queue<Pair<Int, Int>> = ArrayDeque()
            val visited = Array(rows) { BooleanArray(cols) }
            queue += Pair(rows - 1, cols - 1)
            visited[rows - 1][cols - 1] = true
            while (queue.isNotEmpty()) {
                val (row, col) = queue.poll()
                for (i in 1..4) {
                    val (adjRow, adjCol) = when (i) {
                        1 -> Pair(row - 1, col)
                        2 -> Pair(row + 1, col)
                        3 -> Pair(row, col - 1)
                        4 -> Pair(row, col + 1)
                        else -> Pair(-1, -1)
                    }
                    if (adjCol in 0 until cols && adjRow in 0 until rows) {
                        val c = grid[adjRow][adjCol]
                        if (!visited[adjRow][adjCol]) {
                            when (c) {
                                '.' -> {
                                    visited[adjRow][adjCol] = true
                                    queue += Pair(adjRow, adjCol)
                                }
                                'G' -> {
                                    visited[adjRow][adjCol] = true
                                    goodCount--
                                    queue += Pair(adjRow, adjCol)
                                }
                                'B' -> {
                                    exitProcess(-1)
                                }
                            }
                        }
                    }
                }
            }
        }
        if (goodCount != 0) valid = false
        if(valid){
            sb.append("Yes\n")
        } else {
            sb.append("No\n")
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()

@Suppress("DuplicatedCode")
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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}