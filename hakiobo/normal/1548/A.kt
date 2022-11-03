import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val m = br.readInt()
    val higherPower = IntArray(n)
    var numAlive = n
    repeat(m) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        val a = min(u, v)
        val b = max(u, v)
        if (higherPower[a] == 0) {
            numAlive--
        }
        higherPower[a]++
    }
    val q = br.readInt()
    repeat(q) {
        val type = br.readInt()
        when (type) {
            1 -> {
                val u = br.readInt() - 1
                val v = br.readInt() - 1
                val a = min(u, v)
                val b = max(u, v)
                if (higherPower[a] == 0) {
                    numAlive--
                }
                higherPower[a]++
            }
            2 -> {
                val u = br.readInt() - 1
                val v = br.readInt() - 1
                val a = min(u, v)
                val b = max(u, v)
                higherPower[a]--
                if (higherPower[a] == 0) {
                    numAlive++
                }
            }
            3 -> {
                sb.appendLine(numAlive)
            }
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}