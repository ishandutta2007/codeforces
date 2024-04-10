import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val grid = Array(n) {
            readLine()!!.toCharArray()
        }


        val xCounts = IntArray(3)
        val oCounts = IntArray(3)
        for (x in 0 until n) {
            for (y in 0 until n) {
                when (grid[x][y]) {
                    'X' -> {
                        xCounts[(x + y) % 3]++
                    }
                    'O' -> {
                        oCounts[(x + y) % 3]++
                    }
                }
            }
        }
        var xD = -1
        var oD = -1
        var minChange = xCounts.sum() + oCounts.sum()

        for (oDiag in 0 until 3) {
            for (xDiag in 0 until 3) {
                if (oDiag == xDiag) continue
                val change = xCounts[oDiag] + oCounts[xDiag]
                if (change < minChange) {
                    minChange = change
                    oD = oDiag
                    xD = xDiag
                }
            }
        }
        for (x in 0 until n) {
            for (y in 0 until n) {
                when (grid[x][y]) {
                    'X' -> {
                        if ((x + y) % 3 == oD) {
                            grid[x][y] = 'O'
                        }
                    }
                    'O' -> {
                        if ((x + y) % 3 == xD) {
                            grid[x][y] = 'X'
                        }
                    }
                }
            }
        }
        println(grid.joinToString("\n") { it.joinToString("") })
    }
}


private inline fun <T> tm(block: CIO.() -> T) {
    CIO().use(block)
}

private class CIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
    private val r = System.`in`.bufferedReader()
    private var tk = StringTokenizer("")

    fun readWord(): String {
        while (!tk.hasMoreTokens()) {
            tk = StringTokenizer(r.readLine() ?: return "", " ")
        }
        return tk.nextToken()
    }

    fun clearLine() {
        tk = StringTokenizer("")
    }

    fun readLine() = r.readLine()
    fun readInt() = readWord().toInt()
    fun readDouble() = readWord().toDouble()
    fun readLong() = readWord().toLong()
    override fun close() = flush()
}