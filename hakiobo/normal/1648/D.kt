import java.io.BufferedReader
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val q = br.readInt()
    val grid = Array(3) { LongArray(n) { br.readInt().toLong() } }
    val prefix = LongArray(n + 1)
    val suffix = LongArray(n + 1)
    grid[0][0] += grid[1][0]
    for (x in 1 until n) {
        grid[0][0] += grid[1][x]
        grid[0][x] -= grid[1][x - 1]
        grid[2][x - 1] -= grid[1][x]
    }
    for (x in 0 until n) {
        prefix[x + 1] = prefix[x] + grid[0][x]
        suffix[n - x - 1] = suffix[n - x] + grid[2][n - x - 1]
    }

    val seg = SeriousMaxSegment(n, prefix, suffix)
    var ans = Long.MIN_VALUE

    val rCounts = IntArray(n)

    val lefts = IntArray(q)
    val rights = IntArray(q)
    val costs = LongArray(q)
    for (i in 0 until q) {
        lefts[i] = br.readInt() - 1
        rights[i] = br.readInt() - 1
        costs[i] = -br.readInt().toLong()
        rCounts[rights[i]]++
    }
    val dealsR = Array(n) { idx -> IntArray(rCounts[idx]) }
    rCounts.fill(0)
    for(i in 0 until q) {
        dealsR[rights[i]][rCounts[rights[i]]++] = i
    }

    for (r in 0 until n) {
        for (i in dealsR[r]) {
            ans = max(ans, seg.processRange(lefts[i], r, costs[i]))
        }
    }

    println(ans)
}

private class SeriousMaxSegment(nArg: Int, prefix: LongArray, suffix: LongArray) {
    val n = nArg + 1
    val size = n shl 1
    val dp = LongArray(size)
    val pre = LongArray(size)
    val suf = LongArray(size)

    init {
        for (x in 0 until nArg) {
            suf[x + n] = suffix[x]
            pre[x + n] = prefix[x + 1]
            dp[x + n] = pre[x + n] + suf[x + n]
        }
        for (x in n - 1 downTo 1) {
            suf[x] = max(suf[x.left()], suf[x.right()])
            pre[x] = max(pre[x.left()], pre[x.right()])
            dp[x] = max(pre[x.left()] + suf[x.right()], max(dp[x.left()], dp[x.right()]))
        }
    }

    fun processRange(l: Int, r: Int, c: Long): Long {
        val check = getDP(l, r) + c
        val pr = getPre(l, r) + c
        update(r + 1, pr)

        return check
    }

    fun getPre(low: Int, high: Int): Long {
        var l = low + n
        var r = high + n
        var ret = Long.MIN_VALUE
        while (l <= r) {
            if (l and 1 == 1) ret = max(ret, pre[l++])
            if (r and 1 == 0) ret = max(ret, pre[r--])

            l = l shr 1
            r = r shr 1
        }
        return ret
    }

    fun getDP(low: Int, high: Int): Long {
        var l = low + n
        var r = high + n
        var leftRet = Long.MIN_VALUE
        var leftPre = Long.MIN_VALUE shr 1
        var rightRet = Long.MIN_VALUE
        var rightSuf = Long.MIN_VALUE shr 1
        while (l <= r) {
            if (l and 1 == 1) {
                leftRet = max(leftRet, max(dp[l], leftPre + suf[l]))
                leftPre = max(pre[l], leftPre)
                l++
            }
            if (r and 1 == 0) {
                rightRet = max(rightRet, max(dp[r], pre[r] + rightSuf))
                rightSuf = max(suf[r], rightSuf)
                r--
            }
            l = l shr 1
            r = r shr 1
        }
        return max(max(leftRet, rightRet), rightSuf + leftPre)
    }

    fun update(idx: Int, u: Long) {
        var k = idx + n
        while (k != 0) {
            pre[k] = max(u, pre[k])
            if (k < n) {
                dp[k] = max(max(dp[k.left()], dp[k.right()]), pre[k.left()] + suf[k.right()])
            } else {
                dp[k] = pre[k] + suf[k]
            }
            k = k shr 1
        }
    }


    fun Int.left() = this shl 1
    fun Int.right() = (this shl 1) or 1
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