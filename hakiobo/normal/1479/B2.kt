import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val n = readInt()
    val nums = List(n) { readInt() - 1 }
    val nextOccurence = IntArray(n)
    val lastSeen = IntArray(n) { n }
    for (x in nums.lastIndex downTo 0) {
        nextOccurence[x] = lastSeen[nums[x]]
        lastSeen[nums[x]] = x
    }
    var score = 1
    var id1 = 0
    var id2 = -1
    for (x in 1 until n) {
        val p1 = nums[id1]
        val p2 = if (id2 == -1) -1 else nums[id2]
        val num = nums[x]
        when {
            p1 == num -> {
                id1 = x
            }
            p2 == num -> {
                id2 = x
            }
            p2 == -1 -> {
                id2 = x
                score++
            }
            nextOccurence[id1] < nextOccurence[id2] -> {
                score++
                id2 = x
            }
            else -> {
                score++
                id1 = x
            }
        }
    }
    println(score)
}

private inline fun <T> tm(block: B700P1IO.() -> T) {
    B700P1IO().use(block)
}

private class B700P1IO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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