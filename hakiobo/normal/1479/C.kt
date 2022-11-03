import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val l = readInt()
    val r = readInt()
    println("YES")
    val dif = r - l

    when ((dif + 1).countOneBits()) {
        1 -> {
            val n = dif.countOneBits() + 2
            println("$n ${n * (n - 1) / 2}")
            for (start in 0 until n - 1) {
                println("${start + 1} $n $l")
            }
            for (dest in n - 2 downTo 1) {
                val weight = 1 shl (n - 2 - dest)
                for (other in 0 until dest) {
                    println("${other + 1} ${dest + 1} $weight")
                }
            }
        }
        else -> {
            val n = dif.takeHighestOneBit().countTrailingZeroBits() + 3
            val m = ((n - 1) * (n - 2)) / 2 + dif.countOneBits() + 1
            println("$n $m")
            for (start in 0 until n - 1) {
                println("${start + 1} $n $l")
            }
            var otherWeight = 1
            for (dest in n - 2 downTo 2) {
                val weight = 1 shl (n - 2 - dest)
                for (start in 0 until dest) {
                    if (start == 1) {
                        if (weight and dif != 0) {
                            println("${start + 1} ${dest + 1} $otherWeight")
                            otherWeight += weight
                        }
                    } else {
                        println("${start + 1} ${dest + 1} $weight")
                    }
                }
            }
            println("1 2 ${dif.takeHighestOneBit()}")
        }
    }
}

private inline fun <T> tm(block: C700IO.() -> T) {
    C700IO().use(block)
}

private class C700IO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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