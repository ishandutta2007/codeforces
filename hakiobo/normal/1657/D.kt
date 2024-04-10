import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val c = br.readInt()
    val bestPowsByCost = LongArray(c + 1)
    for (i in 0 until n) {
        val cost = br.readInt()
        val power = br.readLong() * br.readLong()
        bestPowsByCost[cost] = max(bestPowsByCost[cost], power)
    }
    for (i in 1..c) {
        bestPowsByCost[i] = max(bestPowsByCost[i], bestPowsByCost[i - 1])
        var curPow = bestPowsByCost[i]
        var j = i
        while (j <= c) {
            bestPowsByCost[j] = max(bestPowsByCost[j], curPow)
            curPow += bestPowsByCost[i]
            j += i
        }
    }
    val m = br.readInt()
    repeat(m) {
        val pow = br.readLong() * br.readLong()
        var high = c + 1
        var low = 1
        while (low < high) {
            val mid = (low + high) shr 1
            if(pow >= bestPowsByCost[mid]) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        if(high == c+1) {
            bw.append("-1 ")
        } else {
            bw.append("$high ")
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

private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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