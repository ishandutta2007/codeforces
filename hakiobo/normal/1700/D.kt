import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val volumes = LongArray(n) { br.readInt().toLong() }
    val totVol = volumes.sum()
    val timeToFillPrefix = LongArray(n)
    val timeToFillAll = LongArray(n)
    timeToFillPrefix[0] = volumes[0]
    timeToFillAll[0] = totVol
    var partialSum = volumes[0]
    for (i in 1 until n) {
        partialSum += volumes[i]
        timeToFillPrefix[i] = max(timeToFillPrefix[i - 1], (partialSum + i) / (i + 1))
        timeToFillAll[i] = max(timeToFillPrefix[i], (totVol + i) / (i + 1))
    }
    val q = br.readInt()
    repeat(q) {
        val t = br.readInt()
        var low = 0
        var high = n
        while (low < high) {
            val mid = (low + high) shr 1
            if (timeToFillAll[mid] <= t) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        if (low == n) {
            bw.appendLine("-1")
        } else {
            bw.appendLine("${low + 1}")
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