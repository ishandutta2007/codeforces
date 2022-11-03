import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var high = 1
        val p = IntArray(n) {
            val num = br.readInt()
            high = max(high, num)
            num
        }
        val minLength = IntArray(n + 1)
        minLength[0] = p.first() + 1
        for (x in 1 until n) {
            minLength[x] = max(p[x - 1], p[x]) + 1
        }
        minLength[n] = p.last() + 1

        var curString = "a".repeat(minLength.first())
        sb.appendLine(curString)
        for (x in 0 until n) {
            val newString = StringBuilder(curString.substring(0, p[x]))
            val cToAdd = 'a' + (((curString[p[x]] - 'a') + 1) % 26)
            newString.append(cToAdd.toString().repeat(minLength[x + 1] - newString.length))

            curString = newString.toString()
            sb.appendLine(curString)
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