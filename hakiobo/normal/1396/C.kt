import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val r1 = br.readInt().toLong()
    val r2 = br.readInt().toLong()
    val r3 = br.readInt().toLong()
    val lowest = min(r1, min(r2, r3))
    val d = br.readInt().toLong()
    val numMonsters = LongArray(n) { br.readInt().toLong() }
    val killAllTime = LongArray(n) { idx ->
        min(r1, r3) * numMonsters[idx] + r3
    }
    val leaveOneHpOnBossTime = LongArray(n) { idx ->
        min(r2, r1 * (numMonsters[idx] + 1))
    }
    val dp = Array(2) { LongArray(n) }
    // 0 -> approaching the room after all rooms before completely dead
    // 1 -> approaching the room with 1hp left on boss in previous room

    for (x in 1 until n) {
        dp[1][x] = dp[0][x - 1] + leaveOneHpOnBossTime[x - 1] + d
        dp[0][x] = dp[0][x - 1] + killAllTime[x - 1] + d
        dp[0][x] = min(dp[0][x], dp[1][x - 1] + killAllTime[x - 1] + 3 * d + lowest)
        dp[0][x] = min(dp[0][x], dp[1][x - 1] + leaveOneHpOnBossTime[x - 1] + 3 * d + 2 * lowest)
    }
    val c1 = dp[0][n - 1] + min(killAllTime[n - 1], 2 * d + lowest + leaveOneHpOnBossTime[n - 1])
    val c2 = dp[1][n - 1] + min(killAllTime[n - 1] + d + lowest, leaveOneHpOnBossTime[n - 1] + d + lowest + d + lowest)
    print(min(c1, c2))
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