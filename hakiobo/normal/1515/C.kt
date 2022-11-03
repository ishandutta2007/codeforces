import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val x = br.readInt()
        val h = List(n) { br.readInt() }
        val res = IntArray(n) { -1 }
        val pq = PriorityQueue<Pair<Int, Int>> { a, b -> a.first.compareTo(b.first) }
        for (i in 0 until  m) {
            res[i] = i + 1
            pq += h[i] to i
        }
        for (i in m until n) {
            val (w, g) = pq.poll()
            res[i] = g + 1
            pq += w + h[i] to g
        }
        sb.append("YES\n")
        sb.append(res.joinToString(" ")).append("\n")
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