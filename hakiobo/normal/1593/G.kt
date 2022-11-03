import java.io.BufferedReader
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val s = br.readLine()
        val q = br.readInt()
        val oddPrefix = IntArray(s.length + 1)
        val evenPrefix = IntArray(s.length + 1)
        for (x in s.indices) {
            oddPrefix[x + 1] += oddPrefix[x]
            evenPrefix[x + 1] += evenPrefix[x]
            if (s[x] == '[' || s[x] == ']') {
                if (x and 1 == 0) {
                    evenPrefix[x + 1]++
                } else {
                    oddPrefix[x + 1]++
                }
            }
        }
        repeat(q) {
            val l = br.readInt()
            val r = br.readInt()
            sb.appendLine((oddPrefix[r] - evenPrefix[r] - oddPrefix[l - 1] + evenPrefix[l - 1]).absoluteValue)
        }
    }
    println(sb)
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