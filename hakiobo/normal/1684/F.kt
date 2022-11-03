import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val nums = IntArray(n) { br.readInt() }
        val lefts = IntArray(m)
        val rights = IntArray(m)
        for (i in 0 until m) {
            lefts[i] = br.readInt() - 1
            rights[i] = br.readInt() - 1
        }
        val furthestRightThatIncludes = IntArray(n) { -1 }

        for (i in 0 until m) {
            furthestRightThatIncludes[lefts[i]] = max(furthestRightThatIncludes[lefts[i]], rights[i])
        }
        for (i in 1 until n) {
            furthestRightThatIncludes[i] = max(furthestRightThatIncludes[i], furthestRightThatIncludes[i - 1])
        }
        val sorted = (0 until n).sortedBy { i -> nums[i] }
        val pairLefts = mutableListOf<Int>()
        val pairRights = mutableListOf<Int>()
        var j = 0
        for (i in 1 until n) {
            val r = sorted[i]
            if (nums[sorted[j]] != nums[r]) {
                j = i
            }
            while (j < i && furthestRightThatIncludes[sorted[j]] < r) j++
            if (j != i) {
                pairLefts += sorted[j]
                pairRights += r
            }
            if (j < i - 1) {
                pairLefts += sorted[i - 1]
                pairRights += r
            }
        }

        var ans = n
        if (pairLefts.isEmpty()) {
            bw.appendLine("0")
        } else {
            val sortedPairs = (0 until pairLefts.size).sortedBy { i -> pairLefts[i] }
            val maxLeft = pairLefts[sortedPairs.last()]
            var rightEndPoint = maxLeft
            var minRightEndPoint = maxLeft
            var i = 0
            while (i < sortedPairs.size && pairLefts[sortedPairs[i]] <= minRightEndPoint) {
                val left = pairLefts[sortedPairs[i]]
                val right = pairRights[sortedPairs[i]]
                ans = min(ans, rightEndPoint - left + 1)
                rightEndPoint = max(rightEndPoint, right)
                minRightEndPoint = min(minRightEndPoint, right)
                i++
            }
            ans = min(ans, rightEndPoint - minRightEndPoint + 1)
            bw.appendLine(ans.toString())
        }
    }
    bw.flush()
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