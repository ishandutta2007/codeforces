import java.io.BufferedReader
import kotlin.math.min

private const val mod = 998_244_353L

private fun getTotBalls(
    baseNums: LongArray,
    cons: Array<MutableList<Int>>,
    revCons: Array<MutableList<Int>>,
    n: Int
): Long {
    val nums = baseNums.copyOf()
    val inDeg = IntArray(n) { i -> revCons[i].size }
    val dumbDp = Array(n) { BooleanArray(n) }
    val queue = IntArray(n) { -1 }
    var inIdx = 0
    for (i in 0 until n) {
        for (j in 0 until min(n, nums[i].toInt())) {
            dumbDp[i][j] = true
        }
        if (inDeg[i] == 0) {
            queue[inIdx++] = i
        }
    }

    for (i in 0 until n) {
        val node = queue[i]
        for (adj in cons[node]) {
            var ct = 0
            for (j in 0 until n) {
                if (ct != 0 && !dumbDp[adj][j]) {
                    dumbDp[adj][j] = true
                    ct--
                }
                if (dumbDp[node][j]) ct++
            }


            nums[adj] += nums[node]
            nums[adj] %= mod
            if (--inDeg[adj] == 0) {
                queue[inIdx++] = adj
            }
        }
    }
    val finalNode = queue.last()
    var seen = false
    var bad = 0L
    for (i in n - 1 downTo 0) {
        if (dumbDp[finalNode][i]) {
            seen = true
        } else if (seen) bad++
    }
    return ( nums[queue.last()] + bad) % mod
}


fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val nums = LongArray(n) { br.readInt().toLong() }
        val cons = Array(n) { mutableListOf<Int>() }
        val revCons = Array(n) { mutableListOf<Int>() }

        repeat(m) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            revCons[v].add(u)
        }

        val baseAns = getTotBalls(nums, cons, revCons, n)

        bw.appendLine("$baseAns")
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