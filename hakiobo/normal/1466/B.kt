import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val notes = List(n){readInt()}.sorted()
        var div = 0
        var cur = 0
        for(note in notes){
            if(note < cur) continue
            if(note == cur){
                cur++
                div++
            } else {
                cur = note
                div++
            }
        }
        println(div)
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