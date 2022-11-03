import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var low = br.readInt()
        var high = br.readInt()
        var lowCost = br.readInt()
        var highCost = lowCost
        var fullRangeCost = lowCost
        sb.appendLine(lowCost)
        repeat(n - 1) {
            val newLow = br.readInt()
            val newHigh = br.readInt()
            val cost = br.readInt()
            if (newLow < low) {
                fullRangeCost = Int.MAX_VALUE
                low = newLow
                lowCost = cost
            }
            if (newHigh > high) {
                fullRangeCost = Int.MAX_VALUE
                high = newHigh
                highCost = cost
            }
            if (newLow == low) {
                lowCost = min(lowCost, cost)
            }
            if (newHigh == high) {
                if (newLow == low) {
                    fullRangeCost = min(fullRangeCost, cost)
                }
                highCost = min(highCost, cost)
            }
            sb.appendLine(min(lowCost + highCost, fullRangeCost))
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