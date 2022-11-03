import java.io.BufferedReader
import kotlin.math.max

fun main() {
    fun solve(n: Int, k: Int): Long {
        var best = Long.MAX_VALUE
        for (start in 0..9) {
            val numAbove = max(0, start + k - 9)
            val numBelow = k + 1 - numAbove
            var sum = 0
            for (x in 0..k) sum += (x + start) % 10
            if (sum > n) continue
            var leftOver = n - sum - numAbove
            if (numAbove == 0) {
                if(leftOver % (k + 1) == 0) {
                    var prefixSum = leftOver / (k + 1)
                    var num = prefixSum.toLong() % 9
                    while (prefixSum >= 9) {
                        num *= 10L
                        num += 9L
                        prefixSum -= 9
                    }
                    num *= 10L
                    num += start
                    best = best.coerceAtMost(num)
                }
            } else {
                var ct = 0
                while (n - sum > (numBelow) * (9 * ct - 1)) {
                    if (leftOver % (k + 1) == 0) {
                        var num = 0L
                        var prefixSum = leftOver / (k + 1) - 9 * ct
                        if (prefixSum >= 8) {
                            num += (prefixSum + 1) % 9
                            prefixSum -= (prefixSum + 1) % 9
                        }
                        while (prefixSum >= 9) {
                            num *= 10L
                            num += 9L
                            prefixSum -= 9
                        }
                        num *= 10L
                        num += prefixSum
                        repeat(ct){
                            num *= 10L
                            num += 9L
                        }
                        num *= 10L
                        num += start
                        best = best.coerceAtMost(num)
                    }
                    leftOver += 9 * numAbove
                    ct++
                }
            }
        }
        return if (best == Long.MAX_VALUE) -1 else best
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    for (case in 0 until t) {
        val n = br.readInt()
        val k = br.readInt()
        sb.append(solve(n, k)).append('\n')
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