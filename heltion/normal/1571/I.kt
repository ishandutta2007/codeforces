import java.util.*

fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readInt()) {
        val n = readInt()
        val l = readInts()
        val r = readInts()
        val sl = l.sortedBy { it }
        val sr = r.sortedBy { it }
        var xL = 1
        var xR = 1000000000
        for (i in 0 until n) {
            xL = maxOf(xL, sl[i] - i)
            xR = minOf(xR, sr[i] - i)
        }
        if (xL > xR)
            println(-1)
        else {
            val x = xL
            println(x)
            val g = Array(n) { mutableListOf<Int>()}
            for (i in 0 until n) g[maxOf(l[i] - x, 0)].add(i)
            val q = PriorityQueue<Long>()
            for (i in 0 until n) {
                for (j in g[i])
                    q.add(r[j] * n.toLong() + j)
                val p = q.poll()
                print("${p % n.toLong() + 1} ")
            }
            println()
        }
    }
}