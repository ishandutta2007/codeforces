import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val difs = LongArray(n + 1)
        for (i in 1..n) {
            difs[i] = br.readInt().toLong()
        }
        for (i in 1..n) {
            difs[i] += difs[i - 1] - br.readInt().toLong()
        }

        val rightsByLeft = Array(n + 1) { mutableListOf<Int>() }
        val leftsByRight = Array(n + 1) { mutableListOf<Int>() }

        repeat(m) {
            val l = br.readInt() - 1
            val r = br.readInt()
            rightsByLeft[l].add(r)
            leftsByRight[r].add(l)
        }
        val uf = GiantRobotUF(n + 1)
        val queue = IntArray(n + 1)
        var outIdx = 0
        var inIdx = 0
        for (i in 0..n) {
            if (difs[i] == 0L) {
                uf.activate(i)
                queue[inIdx++] = i
            }
        }
        while (outIdx < inIdx) {
            val node = queue[outIdx++]
            for (left in leftsByRight[node]) {
                if (uf.valid(left)) {
                    var cur = uf.prev(node)
                    while (cur > left) {
                        if (uf.activate(cur)) {
                            queue[inIdx++] = cur
                        }
                        cur = uf.prev(cur)
                    }
                }
            }
            for (right in rightsByLeft[node]) {
                if (uf.valid(right)) {
                    var cur = uf.next(node)
                    while (cur < right) {
                        if (uf.activate(cur)) {
                            queue[inIdx++] = cur
                        }
                        cur = uf.next(cur)
                    }
                }
            }
        }
        if (outIdx > n) {
            bw.appendLine("YES")
        } else {
            bw.appendLine("NO")
        }
    }
    bw.flush()
}

private class GiantRobotUF(val n: Int) {
    private val reps = IntArray(n) { it }
    private val rank = IntArray(n)
    private val nexts = IntArray(n) { it + 1 }
    private val prevs = IntArray(n) { it - 1 }
    private val color = IntArray(n)
    private fun find(a: Int): Int {
        var k = a
        var d = reps[a]
        while (d != k) {
            reps[k] = reps[d]
            k = d
            d = reps[k]
        }
        return k
    }

    fun next(a: Int): Int = nexts[find(a)]
    fun prev(a: Int): Int = prevs[find(a)]
    fun valid(a: Int): Boolean = color[find(a)] == 1

    fun activate(a: Int): Boolean {
        if (color[a] == 0) {
            color[a] = 1
            val pv = prevs[a]
            val nx = nexts[a]
            if (pv != -1 && color[find(pv)] == 1) {
                union(pv, a)
            }
            if (nx != n && color[find(nx)] == 1) {
                union(nx, a)
            }
            return true
        }
        return false
    }

    private fun union(a: Int, b: Int): Int {
        val u = find(a)
        val v = find(b)
        return if (u == v) {
            u
        } else {
            val pv = min(prevs[u], prevs[v])
            val nx = max(nexts[u], nexts[v])

            if (rank[u] > rank[v]) {
                reps[v] = u
                nexts[u] = nx
                prevs[u] = pv
                u
            } else if (rank[u] < rank[v]) {
                reps[u] = v
                nexts[v] = nx
                prevs[v] = pv
                v
            } else {
                reps[v] = u
                rank[u]++
                nexts[u] = nx
                prevs[u] = pv
                u
            }
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