import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val neededInRange = k + ((n - k + 1) shr 1)
        val a = IntArray(n) { br.readInt() }
        val sorted = a.sorted()
        var bestLow = 1
        var bestHigh = n
        var lowIdx = 0
        var highIdx = 0
        var curLow = 1
        var curHigh = 1
        while ((n - lowIdx) >= neededInRange) {
            while (highIdx < n && sorted[highIdx] <= curHigh) {
                highIdx++
            }
            while (lowIdx < n && sorted[lowIdx] < curLow) {
                lowIdx++
            }
            if (highIdx - lowIdx >= neededInRange) {
                if (curHigh - curLow < bestHigh - bestLow) {
                    bestHigh = curHigh
                    bestLow = curLow
                }
                curLow++
            } else {
                curHigh++
            }
        }
        var begin = 0
        var curBalance = 0
        var numMade = 0
        sb.appendLine("$bestLow $bestHigh")
        for (end in 0 until n) {
            if (a[end] in bestLow..bestHigh) {
                curBalance++
            } else {
                curBalance--
            }
            if (curBalance > 0 && numMade < k - 1) {
                sb.appendLine("${begin + 1} ${end + 1}")
                numMade++
                curBalance = 0
                begin = end + 1
            }
        }
        sb.appendLine("${begin + 1} $n")
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