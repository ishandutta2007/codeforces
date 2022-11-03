import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val owes = Array(n) { IntArray(n) }
    repeat(m) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        val c = br.readInt()
        owes[u][v] += c
        owes[v][u] -= c
    }
    for (mid in 0 until n) {
        for (i in 0 until n) {
            for (j in 0 until n) {
                val toPass = max(0, min(owes[i][mid], owes[mid][j]))
                owes[i][mid] -= toPass
                owes[mid][i] += toPass
                owes[mid][j] -= toPass
                owes[j][mid] += toPass
                owes[i][j] += toPass
                owes[j][i] -= toPass
            }
        }
    }
    var ans = 0
    for (i in 0 until n) {
        for (j in 0 until n) {
            ans += max(0, owes[i][j])
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