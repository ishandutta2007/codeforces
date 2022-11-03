import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val mod = 1_000_000_007L
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val nums = LongArray(n) { readLong() }
        val count = IntArray(60)
        for (x in 0 until 60) {
            val check = 1L shl x
            for (num in nums) {
                if (num and check != 0L) {
                    count[x]++
                }
            }
        }
        val orSum = LongArray(n) {
            var s = 0L
            val num = nums[it]
            for (bit in 0 until 60) {
                val check = 1L shl bit
                s += if (check and num == 0L) {
                    (check % mod) * (count[bit])
                } else {
                    (check % mod) * n
                }
                s %= mod
            }
            s
        }
        val andSum = LongArray(n) {
            var s = 0L
            val num = nums[it]
            for (bit in 0 until 60) {
                val check = 1L shl bit
                if (check and num != 0L) {
                    s += (check % mod) * (count[bit])
                    s %= mod
                }
            }
            s
        }
        var ans = 0L
        for(x in 0 until n){
            val p = (orSum[x] * andSum[x])%mod
            ans += p
            ans %= mod
        }
        println(ans)
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