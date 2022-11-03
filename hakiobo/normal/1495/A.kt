import java.io.PrintWriter
import java.util.*
import kotlin.math.absoluteValue
import kotlin.math.sqrt

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val (miners, mines) = run {
            val miners = mutableListOf<Long>()
            val mines = mutableListOf<Long>()
            repeat(2 * n) {
                val x = readLong()
                val y = readLong()
                if (x == 0L) {
                    miners += y.absoluteValue
                } else {
                    mines += x.absoluteValue
                }
            }
            miners.sorted() to mines.sorted()
        }
        var sum = 0.0
        for (x in 0 until n) {
            sum += sqrt((miners[x] * miners[x] + mines[x] * mines[x]).toDouble())
        }
        println(sum)
    }
}

private inline fun <T> tm(block: A706IO.() -> T) {
    A706IO().use(block)
}

private class A706IO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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