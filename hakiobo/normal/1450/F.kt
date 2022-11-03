import java.io.PrintWriter
import java.util.*
import kotlin.math.max

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val tagCount = IntArray(n)
        var valid = true
        val tags = IntArray(n) {
            val tag = readInt() - 1
            tagCount[tag]++
            if (tagCount[tag] shl 1 > n + 1) {
                valid = false
            }
            tag
        }
        if (valid) {
            val ranges = mutableListOf<Pair<Int, Int>>()
            var prev = -1
            var l = 0
            for (x in 0 until n) {
                if (tags[x] == prev) {
                    ranges += l to x - 1
                    l = x
                }
                prev = tags[x]
            }
            ranges += l to (n - 1)
            val groups = ranges.size
            val tagCount2 = IntArray(n)
            var majorityTag = -1
            for (r in ranges) {
                tagCount2[tags[r.first]]++
                if (tagCount2[tags[r.first]] > (groups + 1)) {
                    majorityTag = tags[r.first]
                }
                tagCount2[tags[r.second]]++
                if (tagCount2[tags[r.second]] > (groups + 1)) {
                    majorityTag = tags[r.second]
                }
            }
            if(majorityTag != -1){
                println(tagCount2[majorityTag] - 2)
            } else {
                println(groups - 1)
            }
        } else {
            println(-1)
        }
    }
}

private inline fun <T> tm(block: FIO.() -> T) {
    FIO().use(block)
}

private class FIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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