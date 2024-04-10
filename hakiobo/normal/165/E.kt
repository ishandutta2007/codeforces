import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val dp = IntArray(1 shl 22) { -1 }
    val nums = IntArray(n) {
        val num = br.readInt()
        dp[num] = num
        num
    }
    val mask = (1 shl 22) - 1
//    for (bit in 0 until 22) {
    for (state in 0 until mask) {
        var vState = state xor mask
        while (vState != 0) {
            val bit = vState.countTrailingZeroBits()
            val new = (1 shl bit) or state
            dp[new] = max(dp[new], dp[state])
            vState = vState xor (1 shl bit)
        }
    }
//    }

    println((0 until n).joinToString(" ") { idx -> dp[nums[idx] xor mask].toString() })
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