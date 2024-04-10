import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun relaxed(x: Long, y: Long): Long {
    return if (x == -1L) y else min(x, y)
}

class Matrix(_n: Int) {
    private val n = _n
    private var a = Array<LongArray>(_n) { LongArray(_n) { -1L } }

    fun set(x: Int, y: Int, z: Long) {
        a[x][y] = z
    }

    fun get(x: Int, y: Int): Long {
        return a[x][y]
    }

    operator fun times(b: Matrix): Matrix {
        var res = Matrix(n)
        for (i in 0 until n) {
            for (j in 0 until n) {
                var cur = -1L
                for (k in 0 until n) {
                    if (get(i, k) > -1 && b.get(k, j) > -1) {
                        cur = relaxed(cur, get(i, k) + b.get(k, j))
                    }
                }
                res.set(i, j, cur)
            }
        }
        return res
    }
}

fun solve() {
    val (n, m, q, s) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong)
    var g = MutableList<MutableList<Int>>(n) { mutableListOf() }
    repeat (m) {
        val (u, v) = readLine()!!.split(' ').map { s -> s.toInt() - 1 }
        g[u].add(v)
    }

    val N = 1 shl n
    var cost = Array(n) { Array(n) { IntArray(N) {-1} } }
    var dist = IntArray(n) { -1 }
    for (fr in 0 until n) {
        for (mask in 0 until N) {
            if ((mask and (1 shl fr)) == 0) {
                continue
            }

            dist.fill(-1)
            dist[fr] = 0
            var q: Queue<Int> = LinkedList<Int>(listOf(fr))
            while (!q.isEmpty()) {
                val v = q.remove()!!
                if ((mask and (1 shl v)) == 0) {
                    continue
                }
                for (x in g[v]) {
                    if (dist[x] == -1) {
                        dist[x] = dist[v] + 1
                        q.add(x)
                    }
                }
            }

            for (to in 0 until n) {
                if ((mask and (1 shl to)) == 0) {
                    cost[fr][to][mask] = dist[to]
                }
            }
        }
    }

    var mat = Matrix(n)

    var min_clean = Array(n) { IntArray(N) { -1 } }

    for (fr in 0 until n) {
        var dp = Array(N) { IntArray(n) { -1 } }
        dp[1 shl fr][fr] = 0
        min_clean[fr][1 shl fr] = 0
        for (mask in 0 until N) {
            for (to in 0 until n) {
                if (dp[mask][to] == -1) {
                    continue
                }
                if (min_clean[fr][mask] == -1 || min_clean[fr][mask] > dp[mask][to]) {
                    min_clean[fr][mask] = dp[mask][to]
                }
                for (nx in 0 until n) {
                    if ((mask and (1 shl nx)) > 0) {
                        continue
                    }
                    val nmask = mask or (1 shl nx)
                    var curval = dp[nmask][nx]
                    if (cost[to][nx][mask] == -1) {
                        continue
                    }
                    if (curval == -1 || curval > dp[mask][to] + cost[to][nx][mask]) {
                        curval = dp[mask][to] + cost[to][nx][mask]
                    }
                    dp[nmask][nx] = curval
                }
            }
        }
        for (to in 0 until n) {
            mat.set(fr, to, dp[N - 1][to].toLong())
        }
    }

    val L = 50
    var pwrs = mutableListOf(mat)
    for (i in 1 until L) {
        val m = pwrs.last()
        pwrs.add(m * m)
    }

    var mask_sum = LongArray(N) { 0 }
    for (mask in 0 until N) {
        for (i in 0 until n) {
            if ((mask and (1 shl i)) > 0) {
                mask_sum[mask] += a[i]
            }
        }
    }

    val mask_order = IntArray(N) { it }.sortedBy { -mask_sum[it] }

    for (i in 0 until n) {
        var permuted = mutableListOf(-1)
        for (mask in 0 until N) {
            permuted.add(min_clean[i][mask_order[mask]])
        }
        for (j in 1..N) {
            permuted[j] = if (permuted[j] == -1) permuted[j - 1] else (if (permuted[j - 1] == -1) permuted[j] else min(permuted[j], permuted[j - 1]))
        }
        min_clean[i] = permuted.toIntArray()
    }
    mask_sum = mask_sum.sorted().reversed().toLongArray()

    val sum = a.sum()

    val qrs = readLine()!!.split(' ').map(String::toLong)
    for (c in qrs) {
        val number_of_times = c / sum
        var m = Matrix(n)
        for (i in 0 until n) {
            m.set(i, i, 0)
        }
        for (i in 0 until L) {
            if ((number_of_times and (1L shl i)) > 0) {
                m *= pwrs[i]
            }
        }
        var l = 0
        var r = N
        while (r > l + 1) {
            val mid = (l + r) / 2
            if (mask_sum[mid] >= c - number_of_times * sum) {
                l = mid
            } else {
                r = mid
            }
        }
        val idx = r

        var ans = Long.MAX_VALUE
        for (i in 0 until n) {
            if (m.get(s - 1, i) == -1L) {
                continue
            }
            ans = min(ans, m.get(s - 1, i) + min_clean[i][idx])
        }
        println(ans)
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}