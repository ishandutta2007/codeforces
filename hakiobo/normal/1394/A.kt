import java.io.BufferedReader
import kotlin.math.max
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val d = br.readInt()
    val m = br.readInt()
    val aAbove = mutableListOf<Int>()
    val aBelow = mutableListOf<Int>()
    repeat(n) {
        val a = br.readInt()
        if (a > m) {
            aAbove += a
        } else {
            aBelow += a
        }
    }
    aAbove.sort()
    aBelow.sort()
    var cum = 0L
    val aAbovePrefix = LongArray(aAbove.size + 1) { idx ->
        if (idx == 0) {
            0
        } else {
            cum += aAbove[idx - 1]
            cum
        }
    }
    cum = 0L
    val aBelowPrefix = LongArray(aBelow.size + 1) { idx ->
        if (idx == 0) {
            0
        } else {
            cum += aBelow[idx - 1]
            cum
        }
    }
    var best = 0L
    var numBans = ((aAbove.size + d) / (d + 1))
    while ((numBans - 1) * (d + 1) + 1 <= n && numBans <= aAbove.size) {
//        val hidden = max(d * (numBans - 1), aAbove.size - numBans)
        val missedBelow = max(0, d * (numBans - 1) - (aAbove.size - numBans))
        val sum = aAbovePrefix.last() - aAbovePrefix[aAbovePrefix.lastIndex - numBans] + aBelowPrefix.last() - aBelowPrefix[missedBelow]
        best = max(sum, best)

        numBans++
    }

    print(best)
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