import java.io.PrintWriter
import java.util.*
import kotlin.math.min

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val p = readInt()
        val k = readInt()
        val a = readLine()
        val x = readInt()
        val y = readInt()
        var best = Int.MAX_VALUE
        for(removed in 0 until k){
            var curCost = 0
            var loc = n - removed
            while (loc >= p){
                if(a[loc - 1] == '0'){
                    curCost += x
                }
                best = min(best, curCost + y * (loc - p))
                loc -= k
            }
        }
        println(best)
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