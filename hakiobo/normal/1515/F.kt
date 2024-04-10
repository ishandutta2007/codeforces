import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val m = br.readInt()
    val x = br.readInt().toLong()
    val asphalts = LongArray(n) { br.readInt().toLong() }
    val uf = F_UF(n)
    val dests = mutableListOf<Int>()
    val cons = MutableList(n) { mutableListOf<Int>() }
    val ptrs = IntArray(n)
    repeat(m) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        cons[u].add(dests.size)
        dests += v
        cons[v].add(dests.size)
        dests += u
    }
    if (asphalts.sum() >= x * (n - 1)) {
        sb.append("YES\n")
        val pq = PriorityQueue<Pair<Long, Int>> { a, b -> b.first.compareTo(a.first) }
        for (y in 0 until n) {
            pq += asphalts[y] to y
        }
        var merges = 0
        while (merges < n - 1) {
            val (asph, node) = pq.poll()
            if (uf.find(node) == node && asphalts[node] == asph) {
                merges++
                while (node == uf.find(dests[cons[node][ptrs[node]]])) {
                    ptrs[node]++
                }
                val roadId = cons[node][ptrs[node]]
                val otherNode = uf.find(dests[roadId])
                ptrs[node]++
                sb.append((roadId shr 1) + 1).append("\n")
                val p = uf.union(node, otherNode)
                val q = if (p == node) otherNode else node
                asphalts[p] += asphalts[q] - x
                if (cons[p].size < cons[q].size) {
                    val tmp = cons[p]
                    cons[p] = cons[q]
                    cons[q] = tmp
                    val tmp2 = ptrs[p]
                    ptrs[p] = ptrs[q]
                    ptrs[q] = tmp2
                }
                for (y in ptrs[q] until cons[q].size) {
                    cons[p].add(cons[q][y])
                }
                pq += asphalts[p] to p
            }
        }
        print(sb)
    } else {
        print("NO\n")
    }
}

private class F_UF(val n: Int) {
    val reps = IntArray(n) { it }
    val rank = IntArray(n)


    fun find(a: Int): Int {
        var k = a
        var d = reps[a]
        while (d != k) {
            reps[k] = reps[d]
            k = d
            d = reps[k]
        }
        return k
    }

    fun union(a: Int, b: Int): Int {
        val u = find(a)
        val v = find(b)
        return if (u == v) {
            u
        } else if (rank[u] > rank[v]) {
            reps[v] = u
            u
        } else if (rank[u] < rank[v]) {
            reps[u] = v
            v
        } else {
            reps[v] = u
            rank[u]++
            u
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