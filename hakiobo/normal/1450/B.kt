import java.io.PrintWriter
import java.util.*
import kotlin.math.absoluteValue

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val k = readInt()
        val x = IntArray(n)
        val y = IntArray(n) {
            x[it] = readInt()
            readInt()
        }
        var solved = false
        for (a in 0 until n) {
            var good = true
            for (b in 0 until n) {
                if ((x[a] - x[b]).absoluteValue + (y[a] - y[b]).absoluteValue > k) {
                    good = false
                }
            }
            solved = solved || good
        }
        println(if (solved) 1 else -1)
    }
}

private inline fun <T> tm(block: BIO.() -> T) {
    BIO().use(block)
}

private class BIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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