import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val ary = IntArray(n) { br.readInt() }
        var numAns = 0
        for (start in 0 until n) {
            for (end in start until min(ary.size, start + 4)) {
                when (end - start) {
                    in 0..1 -> numAns++
                    2 -> {
                        var increasing = true
                        var decreasing = true
                        for (x in 0 until 2) {
                            if (ary[start + x] < ary[start + x + 1]) decreasing = false
                            if (ary[start + x] > ary[start + x + 1]) increasing = false
                        }
                        if (!increasing && !decreasing) numAns++
                    }
                    3 -> {
                        var good = true
                        for (numToExclude in 0 until 4) {
                            val toUse = IntArray(3) { idx ->
                                if (idx >= numToExclude) start + idx + 1 else start + idx
                            }
                            var increasing = true
                            var decreasing = true
                            for (x in 0 until 2) {
                                if (ary[toUse[x]] < ary[toUse[x + 1]]) decreasing = false
                                if (ary[toUse[x]] > ary[toUse[x + 1]]) increasing = false
                            }
                            if (increasing || decreasing) good = false
                        }
                        if (good) numAns++
                    }
                }
            }
        }
        sb.appendLine(numAns)
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