import java.io.BufferedReader
import java.util.*

private val dummy = Pair(0, 0)

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLong()
        val cons = Array(n) { mutableListOf<Pair<Int, Int>>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            val w = br.readInt()
            val c = br.readInt() - 1
            cons[u].add(Pair(v, (w shl 1) + c))
            cons[v].add(Pair(u, (w shl 1) + c))
        }
        val leafsBelow = IntArray(n)
        for (x in 1 until n) {
            if (cons[x].size == 1) {
                leafsBelow[x]++
            }
        }
        var totalSum = 0L
        val moves = Array(2) { mutableListOf<Long>() }

        IteratorDFS2(cons) { cur, nx, weight ->
            if (cur != nx) {
                leafsBelow[nx] += leafsBelow[cur]
                var w = weight shr 1
                val c = weight and 1
                totalSum += leafsBelow[cur] * w.toLong()
                while (w > 0) {
                    moves[c].add(leafsBelow[cur] * ((w + 1L) shr 1))
                    w /= 2
                }

            }
        }
        moves[0].sortDescending()
        moves[1].sortDescending()
        var curcost = 2 * moves[1].size
        var minCost = curcost + moves[0].size
        var leftPtr = moves[1].lastIndex
        for (x in moves[1]) {
            totalSum -= x
        }
        for (x in 0..moves[0].size) {
            while (leftPtr != -1 && totalSum <= s) {
                minCost = minCost.coerceAtMost(curcost)
                totalSum += moves[1][leftPtr]
                leftPtr--
                curcost -= 2
            }
            if(totalSum <= s){
                minCost = minCost.coerceAtMost(curcost)
            }
            if (x != moves[0].size) {
                curcost++
                totalSum -= moves[0][x]
            }
        }
        sb.append(minCost).append('\n')
    }
    print(sb)
}

private class IteratorDFS2(c: Array<out Iterable<Pair<Int, Int>>>, val p: Array<Pair<Int, Int>> = Array(c.size) { dummy }, root: Int = 0, b: (Int, Int, Int) -> Unit) {
//    constructor(c: Array<out Iterable<Int>>, p: IntArray = IntArray(c.size), root: Int = 0, b: (Boolean, Int, Int) -> Unit) : this(c.toList(), p, root, b)

    init {
        val i = ArrayDeque<Iterator<Pair<Int, Int>>>()
        var cur = root
        p[root] = Pair(root, 0)
        i.push(c[root].iterator())
        while (i.isNotEmpty()) {
            if (i.peek().hasNext()) {
                val next = i.peek().next()
                if (next.first != p[cur].first) {
                    p[next.first] = Pair(cur, next.second)
                    i.push(c[next.first].iterator())
                    cur = next.first
                }
            } else {
                val pn = p[cur]
                b(cur, pn.first, pn.second)
                cur = pn.first
                i.pop()
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

private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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