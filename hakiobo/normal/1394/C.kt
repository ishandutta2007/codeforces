import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
//    val sb = StringBuilder()
    val n = br.readInt()
    val bCt = IntArray(n)
    val nCt = IntArray(n)
    var minB = Int.MAX_VALUE
    var maxB = 0
    var minN = Int.MAX_VALUE
    var maxN = 0
    var maxBNDif = 0
    var maxNBDif = 0
    for (x in 0 until n) {
        val s = br.readLine()

        for (c in s) {
            if (c == 'B') {
                bCt[x]++
            } else {
                nCt[x]++
            }
        }
        minB = min(minB, bCt[x])
        maxB = max(maxB, bCt[x])
        minN = min(minN, nCt[x])
        maxN = max(maxN, nCt[x])
    }
    var bestB = maxB
    var bestN = maxN
    fun check(t: Int): Boolean {
        var lowB = 0
        var highB = Int.MAX_VALUE
        var lowN = 0
        var highN = Int.MAX_VALUE
        var lowDif = Int.MIN_VALUE
        var highDif = Int.MAX_VALUE
        for (x in 0 until n) {
            lowB = max(lowB, bCt[x] - t)
            highB = min(highB, bCt[x] + t)
            lowN = max(lowN, nCt[x] - t)
            highN = min(highN, nCt[x] + t)
            lowDif = max(lowDif, bCt[x] - nCt[x] - t)
            highDif = min(highDif, bCt[x] - nCt[x] + t)
        }

        highB = min(highB, highN + highDif)
        lowB = max(lowB, lowN + lowDif)
        highN = min(highN, highB - lowDif)
        lowN = max(lowN, lowB - highDif)
        highDif = min(highDif, highB - lowN)
        lowDif = max(lowDif, lowB - highN)
        if (lowB > highB || lowN > highN || lowDif > highDif) return false
        bestB = highB
        bestN = highN
        return true
    }


    var high = max(maxB - minB, maxN - minN)
    var low = 0
    var mid = (high + low) shr 1
    while (low != high) {
        if (check(mid)) {
            high = mid
        } else {
            low = mid + 1
        }
        mid = (high + low) shr 1
    }
    println(mid)
    print("B".repeat(bestB))
    print("N".repeat(bestN))
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