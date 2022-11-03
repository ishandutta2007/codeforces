import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val acceptanceTimes = IntArray(n) { br.readInt() }
        val sorted = IntArray(n) { it }.sortedBy { acceptanceTimes[it] }
        var leftPtr = 0
        var rightPtr = n - 2
        sb.append(sorted.last() + 1).append(" ")
        while (leftPtr <= rightPtr) {
            val onRight = acceptanceTimes[sorted[leftPtr]] - 1
            for (idx in rightPtr downTo max(rightPtr - onRight + 1, leftPtr + 1)) {
                sb.append(sorted[idx] + 1).append(" ")
            }
            sb.append(sorted[leftPtr] + 1).append(" ")
            rightPtr -= onRight
            leftPtr++
        }
        sb.append("\n")
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