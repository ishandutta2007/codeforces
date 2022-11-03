import java.io.BufferedReader
import kotlin.math.absoluteValue
import kotlin.math.max
import kotlin.math.sign

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = LongArray(n) { br.readInt().toLong() }
    val dp = Array(n) { LongArray(2) }
    val borderElement = Array(n) { IntArray(2) }
    borderElement[0][0] = 0
    borderElement[0][1] = 0
    var lastDifSign = 0
    for (i in 1 until n) {
        val difSign = (a[i] - a[i - 1]).sign
        if (difSign == lastDifSign) {
            borderElement[i][0] = borderElement[i - 1][0]
            borderElement[i][1] = borderElement[i - 1][1]
            dp[i][0] = dp[i - 1][0]
            dp[i][1] = dp[i - 1][1]
        } else {
            if (difSign == 0) {
                val score = max(
                    dp[i - 1][0] + (a[i] - a[borderElement[i - 1][0]]).absoluteValue,
                    dp[i - 1][1] + (a[i] - a[borderElement[i - 1][1]]).absoluteValue
                )
                dp[i][0] = score
                dp[i][1] = score
                borderElement[i][0] = i
                borderElement[i][1] = i
            } else if (lastDifSign != 0) {
                val zCA =
                    dp[i - 1][0] + if (i - 2 >= borderElement[i - 1][0]) (a[i - 2] - a[borderElement[i - 1][0]]).absoluteValue else 0
                val zCB =
                    dp[i - 1][1] + if (i - 2 >= borderElement[i - 1][1]) (a[i - 2] - a[borderElement[i - 1][1]]).absoluteValue else 0
                val oCA =
                    dp[i - 1][0] + if (i - 1 >= borderElement[i - 1][0]) (a[i - 1] - a[borderElement[i - 1][0]]).absoluteValue else 0
                val oCB =
                    dp[i - 1][1] + if (i - 1 >= borderElement[i - 1][1]) (a[i - 1] - a[borderElement[i - 1][1]]).absoluteValue else 0
                dp[i][0] = max(zCA, zCB)
                borderElement[i][0] = i - 1
                dp[i][1] = max(oCA, oCB)
                borderElement[i][1] = i
            } else {
                borderElement[i][0] = borderElement[i - 1][0]
                borderElement[i][1] = borderElement[i - 1][1]
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = dp[i - 1][1]
            }
            lastDifSign = difSign
        }

    }
    val ans = max(
        dp.last()[0] + (a.last() - a[borderElement.last()[0]]).absoluteValue,
        dp.last()[1] + (a.last() - a[borderElement.last()[1]]).absoluteValue
    )
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