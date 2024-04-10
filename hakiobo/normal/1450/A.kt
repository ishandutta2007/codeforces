import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readWord()
        val numT = a.count { it == 't' }
        println("${a.filter { it != 't' }}${"t".repeat(numT)}")
    }
}

private inline fun <T> tm(block: AIO.() -> T) {
    AIO().use(block)
}

private class AIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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