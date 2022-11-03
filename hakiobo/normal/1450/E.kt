import java.io.PrintWriter
import java.util.*
import kotlin.math.min

fun main() = tm {
    val n = readInt()
    val m = readInt()
    val path = Array(n) { IntArray(n) { 10_000 } }
    repeat(m) {
        val u = readInt() - 1
        val v = readInt() - 1
        val e = readInt()
        path[u][v] = 1
        path[v][u] = if (e == 1) -1 else 1
    }
    val colors = IntArray(n)
    var valid = true
    val q = ArrayDeque<Int>()
    q += 0
    colors[0] = 1
    while (q.isNotEmpty()) {
        val node = q.poll()
        val color = colors[node]
        for (x in 0 until n) {
            if (path[node][x] != 10_000) {
                if (colors[x] == 0) {
                    colors[x] = -color
                    q += x
                } else if (colors[x] == color) {
                    valid = false
                }
            }
        }
    }
    if (valid) {
        for (x in 0 until n) {
            path[x][x] = 0
        }
        for (mid in 0 until n) {
            for (x in 0 until n) {
                for (y in 0 until n) {
                    path[x][y] = min(path[x][y], path[x][mid] + path[mid][y])
                }
            }
        }
        for (x in 0 until n) {
            if (path[x][x] < 0) {
                valid = false
            }
        }
        if (valid) {
            println("YES")
            var low = -1
            var largestDif = -1
            for (x in 0 until n) {
                for (y in 0 until n) {
                    if (path[x][y] > largestDif) {
                        low = x
                        largestDif = path[x][y]
                    }
                }
            }
            val ans = IntArray(n) { path[low][it] }
            println(largestDif)
            println(ans.joinToString(" "))
        } else {
            println("NO")
        }
    } else {
        println("NO")
    }

}

private inline fun <T> tm(block: EIO.() -> T) {
    EIO().use(block)
}

private class EIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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