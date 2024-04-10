import java.io.PrintWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() = tm {
    val n = readInt()
    val location = IntArray(n) { -1 }

    val perm = List(n) {
        val p = readInt() - 1
        location[p] = it
        p
    }

    val seen = BooleanArray(n)

    val chain = IntArray(n)
    var largestChain = 0
    var largestChain2 = -1
    var unique = false
    for (x in 0 until n) {
        val v = location[x]
        seen[v] = true
        if (v + 1 in 0 until n) {
            if (seen[v + 1]) {
                chain[v] = chain[v + 1] + 1
            }
        }
        var other = -1
        if (v - 1 in 0 until n) {
            if (seen[v - 1]) {
                if (chain[v] != 0) {
                    chain[v] = max(chain[v + 1], chain[v - 1]) + 1
                    other = min(chain[v + 1], chain[v - 1]) + 1
                } else {
                    chain[v] = chain[v - 1] + 1
                }
            }
        }
        if (chain[v] > largestChain) {
            largestChain = chain[v]
            largestChain2 = other
            unique = true
        } else if (chain[v] == largestChain) {
            unique = false
            largestChain2 = -1
        }
    }
    if (!unique) {
        println(0)
    } else if (largestChain2 == -1) {
        println(0)
    } else if (largestChain and 1 == 1) {
        println(0)
    } else if (largestChain == largestChain2) {
        println(1)
    } else {
        println(0)
    }
}

private inline fun <T> tm(block: B706IO.() -> T) {
    B706IO().use(block)
}

private class B706IO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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