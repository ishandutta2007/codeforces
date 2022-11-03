
import java.lang.System.`in`
import kotlin.math.max

fun main() {
    val br = `in`.bufferedReader()
    val (n, h, l, r) = br.readLine().split(' ').map(String::toInt)
    val dp = Array(n) {
        IntArray(n) {
            -1
        }
    }
    val times = br.readLine().split(' ').map(String::toInt)
    print(solve(0, h, l, r, dp, times, 0, 0))
}

private fun solve(numSleep: Int, h: Int, l: Int, r: Int, dp: Array<IntArray>, times: List<Int>, curTime: Int, offsets: Int): Int {
    if (numSleep == dp.size) {
        return 0
    }
    if (dp[numSleep][offsets] == -1) {
        val delayTime = (curTime + times[numSleep] - 1) % h
        var delayAfter = solve(numSleep + 1, h, l, r, dp, times, delayTime, offsets + 1)
        val regTime = (curTime + times[numSleep]) % h
        var regAfter = solve(numSleep + 1, h, l, r, dp, times, regTime, offsets)
        if (delayTime in l..r) {
            delayAfter++
        }
        if (regTime in l..r) {
            regAfter++
        }
        dp[numSleep][offsets] = max(regAfter, delayAfter)
    }
    return dp[numSleep][offsets]
}