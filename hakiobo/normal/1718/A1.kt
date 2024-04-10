import java.io.BufferedReader
import java.util.TreeMap
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val prefixXor = IntArray(n + 1)
        val latest = TreeMap<Int, Int>()
        val dp = IntArray(n + 1) { Int.MAX_VALUE } // means we have first *i* numbers done
        dp[0] = 0
        latest[0] = 0
        for (i in 1..n) {
            prefixXor[i] = prefixXor[i - 1] xor a[i - 1]
            val prev = latest[prefixXor[i]]
            dp[i] = dp[i - 1] + 1
            if (prev != null) {
                dp[i] = min(dp[i], dp[prev] + i - prev - 1)
            }
            latest[prefixXor[i]] = i
        }
        bw.appendLine("${dp.last()}")


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