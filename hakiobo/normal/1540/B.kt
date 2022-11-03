import java.io.BufferedReader
import kotlin.math.min

fun main() {
    fun modPow(n: Long, k: Int, m: Long): Long {
        if (k == 0) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1) {
            half %= m
            half *= n
        }
        return half % m
    }

    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val mod = 1_000_000_007L
    val cons = Array(n) { mutableListOf<Int>() }
    repeat(n - 1) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        cons[u].add(v)
        cons[v].add(u)
    }
    val invN = modPow(n.toLong(), (mod - 2).toInt(), mod)
    val twoPows = LongArray(n + 1)
    twoPows[0] = 1L
    for (x in 1..n) {
        twoPows[x] = (twoPows[x - 1] shl 1) % mod
    }
    val dp = Array(n + 1) { LongArray(n + 1) }
    for (x in 1..n) {
        dp[0][x] = twoPows[x - 1]
    }
    for (x in 1..n) {
        for (y in 1..n) {
            dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % mod
        }
    }
    val invTwoPows = LongArray(n + 1)
    invTwoPows[0] = 1L
    invTwoPows[1] = (mod + 1) shr 1
    for (x in 2..n) {
        invTwoPows[x] = (invTwoPows[x - 1] * invTwoPows[1]) % mod
    }

    var ans = 0L
    for (root in 0 until n) {
        var part = root.toLong()
        val tour = IntArray((n shl 1) - 1) { -1 }
        val parent = IntArray(n) { -1 }
        val times = IntArray(n)
        val depths = IntArray(n)
        var t = 0
        fun dfs(node: Int) {
            times[node] = t
            tour[t++] = depths[node]
            for (adj in cons[node]) {
                if (adj != parent[node]) {
                    parent[adj] = node
                    depths[adj] = depths[node] + 1
                    dfs(adj)
                    tour[t++] = depths[node]
                }
            }
        }
        depths[root] = 0
        dfs(root)
        val sparseTable = SparseMinTable(tour)
        for (x in 0 until n) {
            if (x == root) continue
            for (y in x + 1 until n) {
                if (y == root) continue
                var d1 = depths[x]
                var d2 = depths[y]
                val lcaD = sparseTable.getMinRange(times[x], times[y])
                d1 -= lcaD
                d2 -= lcaD
                part += (invTwoPows[d1 + d2 - 1] * dp[d2][d1]) % mod
                part %= mod
            }
        }

        part *= invN
        part %= mod
        ans += part
        ans %= mod
    }
    print(ans)
}

private class SparseMinTable(nums: IntArray) {
    val n = nums.size
    val table = List(
        if (Integer.highestOneBit(n) == n) Integer.numberOfTrailingZeros(n) + 1
        else Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1
    ) { IntArray(n) }

    init {
        for (x in 0 until n) {
            table[0][x] = nums[x]
        }
        for (bit in 1 until table.size) {
            val pow = 1 shl bit
            var x = 0
            while (x + pow <= n) {
                table[bit][x] = min(table[bit - 1][x], table[bit - 1][x + (pow shr 1)])
                x++
            }
        }
    }

    fun getMinRange(start: Int, end: Int): Int {
        return if (start <= end) {
            val dif = end - start + 1
            val high = Integer.highestOneBit(dif)
            val bit = Integer.numberOfTrailingZeros(high)
            if (high == dif) {
                table[bit][start]
            } else {
                min(table[bit][start], table[bit][end - high + 1])
            }
        } else {
            getMinRange(end, start)
        }
    }
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