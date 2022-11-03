import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val l = br.readInt()
        val r = br.readInt()
        val netColors = IntArray(n)
        repeat(l) {
            val c = br.readInt() - 1
            netColors[c]++
        }
        repeat(r) {
            val c = br.readInt() - 1
            netColors[c]--
        }
        var moves = 0
        var curL = l
        var curR = r
        var unMatchedLeft = 0
        var unMatchedRight = 0
        for (x in 0 until n) {
            if (netColors[x] >= 2 && curL > curR) {
                val d = min((netColors[x] shr 1) shl 1, curL - curR)
                curL -= d
                moves += d shr 1
                unMatchedLeft += netColors[x] - d
            } else if (netColors[x] <= -2 && curR > curL) {
                val d = min(((-netColors[x]) shr 1) shl 1, curR - curL)
                curR -= d
                moves += d shr 1
                unMatchedRight += -netColors[x] - d
            } else if (netColors[x] > 0) {
                unMatchedLeft += netColors[x]
            } else {
                unMatchedRight -= netColors[x]
            }
        }
        moves += max(unMatchedLeft, unMatchedRight)
        sb.append(moves).append("\n")

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