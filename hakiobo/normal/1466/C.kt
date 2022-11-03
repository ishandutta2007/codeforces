import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val poem = readLine()
        val n = poem.length
        val changed = BooleanArray(n)
        var changes = 0
        for (x in 0 until n) {
            if (changed[x]) continue
            val c = poem[x]
            if (x + 1 < n && poem[x + 1] == c) {
                changed[x + 1] = true
                changes++
            }
            if (x + 2 < n && poem[x + 2] == c) {
                changed[x + 2] = true
                changes++
            }
        }
        println(changes)
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