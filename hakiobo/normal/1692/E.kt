import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readInt()
        val nums = IntArray(n) { br.readInt() }
        var start = 0
        var end = 0
        var curSum = 0
        var ans = -1
        while (end < n) {
            if (curSum <= s) {
                if (curSum == s) {
                    ans = max(ans, end - start)
                }
                curSum += nums[end++]
            } else {
                curSum -= nums[start++]
            }
        }
        if (curSum == s) {
            ans = max(ans, end - start)
        }
        if (ans == -1) {
            bw.appendLine("-1")
        } else {
            bw.appendLine("${n - ans}")
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