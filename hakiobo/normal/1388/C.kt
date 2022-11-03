import java.io.BufferedReader
import java.util.*
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val totalPop = br.readInt()
        val pops = IntArray(n) { br.readInt() }
        val indices = IntArray(n) { br.readInt() }
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        val p = IteratorDFS(cons) { down, curr, next ->
            if (!down) {
                if (curr != next) {
                    pops[next] += pops[curr]
                }
            }
        }.p
        var good = true

        val numHappy = IntArray(n) {
            val thing = indices[it] + pops[it]
            if (thing and 1 == 1) good = false
            if (indices[it].absoluteValue > pops[it]) good = false
            thing shr 1
        }
        val numHappyBelow = IntArray(n)
        for (x in 1 until n) {
            numHappyBelow[p[x]] += numHappy[x]
        }
        for (x in 0 until n) {
            if (numHappy[x] < numHappyBelow[x]) {
                good = false
            }
        }
        if (good) {
            sb.append("YES\n")
        } else {
            sb.append("NO\n")
        }
    }

    print(sb)
}


private class IteratorDFS(c: List<Iterable<Int>>, val p: IntArray = IntArray(c.size), root: Int = 0, b: (Boolean, Int, Int) -> Unit) {
    constructor(c: Array<out Iterable<Int>>, p: IntArray = IntArray(c.size), root: Int = 0, b: (Boolean, Int, Int) -> Unit) : this(c.toList(), p, root, b)

    init {
        val i = ArrayDeque<Iterator<Int>>()
        var cn = root
        p[root] = root
        i.push(c[root].iterator())
        while (i.isNotEmpty()) {
            if (i.peek().hasNext()) {
                val nx = i.peek().next()
                if (nx != p[cn]) {
                    p[nx] = cn
                    b(true, cn, nx)
                    i.push(c[nx].iterator())
                    cn = nx
                }
            } else {
                val pn = p[cn]
                b(false, cn, pn)
                cn = pn
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