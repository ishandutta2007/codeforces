import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val nums = IntArray(n) { readInt() }
        val difs = BooleanArray(51)
        var ans = 0
        for(x in 0 until n){
            for(y in x + 1 until n){
                val d = nums[y] - nums[x]
                if(!difs[d]){
                    difs[d] = true
                    ans++
                }
            }
        }
        println(ans)
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