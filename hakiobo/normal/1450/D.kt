import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val nums = Array(n) { readInt() - 1 }
        val ans = IntArray(n)
        val inCounts = IntArray(n)
        var distinct = 0
        for (num in nums) {
            if (num < n) {
                if(inCounts[num] == 0){
                    distinct++
                }
                inCounts[num]++
            }
        }
        var l = 0
        var r = n - 1
        for (x in 0 until (n - 1)) {
            if(inCounts[x] > 0){
                ans[n - x - 1] = 1
            }
            if(nums[l] == x){
                l++
            } else if(nums[r] == x){
                r--
            } else {
                break
            }
            if(inCounts[x] != 1){
                break
            }
        }
        if(distinct == n){
            ans[0] = 1
        }

        println(ans.joinToString(""))
    }
}

private inline fun <T> tm(block: DIO.() -> T) {
    DIO().use(block)
}

private class DIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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