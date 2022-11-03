import java.io.BufferedReader
import java.util.*
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val childrenS = List(n) { mutableListOf<Int>() }
        val childrenK = List(n) { mutableListOf<Int>() }

        val parentsS = IntArray(n) { node ->
            if (node == 0) -1 else {
                val p = br.readInt() - 1
                childrenS[p] += node
                p
            }
        }
        val parentsK = IntArray(n) { node ->
            if (node == 0) -1 else {
                val p = br.readInt() - 1
                childrenK[p] += node
                p
            }
        }

        val kIns = IntArray(n)
        val kOuts = IntArray(n)
        val times = IntArray(n shl 1)
        var time = 0
        fun r(node: Int) {
            times[time] = node
            kIns[node] = time++
            for (child in childrenK[node]) {
                r(child)
            }
            times[time] = node
            kOuts[node] = time++
        }
        r(0)
        val curTimes = TreeSet<Int>()
        curTimes += kIns[0]
        curTimes += kOuts[0]
        var ans = 0
        fun r2(node: Int) {
            ans = max(curTimes.size shr 1, ans)
            for (child in childrenS[node]) {
                val before = curTimes.floor(kIns[child])
                val before2 = curTimes.floor(kOuts[child])
                if (before != before2) {
                    r2(child)
                    // outside conflict
                } else if (before2 != null && kOuts[times[before2]] > kOuts[child]) {
                    val ancestor = times[before2]
                    curTimes -= kIns[ancestor]
                    curTimes -= kOuts[ancestor]
                    curTimes += kIns[child]
                    curTimes += kOuts[child]
                    r2(child)
                    curTimes += kIns[ancestor]
                    curTimes += kOuts[ancestor]
                    curTimes -= kIns[child]
                    curTimes -= kOuts[child]
                    // inside conflict
                } else {
                    curTimes += kIns[child]
                    curTimes += kOuts[child]
                    r2(child)
                    curTimes -= kIns[child]
                    curTimes -= kOuts[child]
                    // no conflict
                }
            }
        }
        r2(0)
        sb.appendLine(ans)
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