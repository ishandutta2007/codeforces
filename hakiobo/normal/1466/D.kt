import java.io.PrintWriter
import java.util.*

fun main() = tm {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val weights = LongArray(n) { readLong() }
        val cons = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = readInt() - 1
            val v = readInt() - 1
            cons[u] += v
            cons[v] += u
        }
        var low = weights.first()
        var root = 0
        for (x in 1 until n) {
            if (weights[x] < low) {
                low = weights[x]
                root = x
            }
        }
        val ans = mutableListOf<Long>()
        val parent = IntArray(n) { -1 }
        val queue = ArrayDeque<Int>()
        queue += root
        while (queue.isNotEmpty()) {
            val cur = queue.poll()
            for (adj in cons[cur]) {
                if (adj != parent[cur]) {
                    parent[adj] = cur
                    queue += adj
                    ans += weights[cur]
                }
            }
        }

        val sorted = ans.sortedDescending()
        val init = weights.sum()
        print(init)
        var c = 0L
        for (x in 1 until n - 1) {
            c += sorted[x - 1]
            print(" ${init + c}")
        }
        println()
    }
}

private inline fun <T> tm(block: DIO.() -> T) {
    DIO().use(block)
}

private class DIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
    private val r = System.`in`.bufferedReader()
    private var tk = StringTokenizer("")

    fun readWord(): String {
        while (!tk.hasMoreTokens()) {
            tk = StringTokenizer(r.readLine() ?: return "", " ")
        }
        return tk.nextToken()
    }

    fun clearLine() {
        tk = StringTokenizer("")
    }

    fun readLine() = r.readLine()
    fun readInt() = readWord().toInt()
    fun readDouble() = readWord().toDouble()
    fun readLong() = readWord().toLong()
    override fun close() = flush()
}

private class DTreeDFS(
    c: List<Iterable<Int>>,
    val p: IntArray = IntArray(c.size),
    root: Int = 0,
    b: (Boolean, Int, Int) -> Unit
) {
    constructor(
        c: Array<out Iterable<Int>>,
        p: IntArray = IntArray(c.size),
        root: Int = 0,
        b: (Boolean, Int, Int) -> Unit
    ) : this(c.toList(), p, root, b)

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
                b(false, cn, p[cn])
                cn = p[cn]
                i.pop()
            }
        }
    }
}