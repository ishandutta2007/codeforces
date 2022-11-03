import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val n = readInt()
    if (n >= 100) {
        println(1)
        return@tm
    }
    val a = IntArray(n) { readInt() }
    var highestOneBit = 1 shl 31
    var streak = 0
    var best = Int.MAX_VALUE
    var curJoined = 0
    for (idx in n - 1 downTo 0) {
        val num = a[idx]
        if (num.takeHighestOneBit() == highestOneBit) {
            streak++
            if (streak == 3) {
                best = best.coerceAtMost(curJoined + 1)
                if (curJoined != 0) {
                    curJoined = 0
                    streak--
                }
            }
        } else {
            highestOneBit = num.takeHighestOneBit()
            if (streak == 1 || streak == 0) {
                streak = 1
                curJoined = 0
            } else if (streak == 2) {

                var c = curJoined
                var y = a[idx + 1]
                for (x in idx downTo 0) {
                    c++
                    y = y xor a[x]
                    if (y > a[idx + 2]) {
                        best = best.coerceAtMost(c)
                        break
                    }
                }

                a[idx + 1] = a[idx + 1] xor a[idx + 2]
                curJoined++
                streak = 1
                if (highestOneBit < a[idx + 1].takeHighestOneBit()) {
                    curJoined = 0
                } else if (a[idx] > a[idx + 1]) {
                    best = best.coerceAtMost(curJoined)
                    curJoined = 0
                } else {
                    streak++
                }
            }
        }
    }
    if (best == Int.MAX_VALUE) {
        println(-1)
    } else {
        println(best)
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