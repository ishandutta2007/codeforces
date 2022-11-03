import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val seq = LongArray(n) { br.readInt().toLong() }
    var ans = 0L
    for (start in 0 until n step 2) {
        var lowOpen = 1L
        var highOpen = seq[start]
        var lowClose = 0L
        var highClose = 0L

        for (end in start + 1 until n step 2) {
            lowClose++
            highClose += seq[end]
            lowOpen = max(lowOpen, lowClose)
            ans += max(0, min(highClose, highOpen) - max(lowOpen, lowClose) + 1)
            lowOpen = max(lowOpen, highClose)
            if (lowOpen > highOpen) break
            lowClose = highClose
            if (end + 1 < n) {
                lowOpen += seq[end + 1]
                highOpen += seq[end + 1]
            }
        }
    }
    println(ans)
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