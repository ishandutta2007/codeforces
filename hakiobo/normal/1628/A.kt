import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val occurrences = Array(n + 1) { mutableListOf<Int>() }
        val idxs = IntArray(n + 1)
        val nums = IntArray(n) { idx ->
            val num = br.readInt()
            occurrences[num].add(idx)
            num
        }
        val b = mutableListOf<Int>()
        var curIdx = 0
        while (curIdx < n) {
            var nextVal = 0
            var nextIdx = curIdx
            while (idxs[nextVal] < occurrences[nextVal].size) {
                nextIdx = max(nextIdx, occurrences[nextVal][idxs[nextVal]])
                nextVal++
            }
            b += nextVal
            for (x in curIdx..nextIdx) {
                idxs[nums[x]]++
            }
            curIdx = nextIdx + 1
        }
        sb.appendLine(b.size)
        sb.appendLine(b.joinToString(" "))
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