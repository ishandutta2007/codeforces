import java.io.PrintWriter
import java.util.*

fun main() = tm {
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

    val n = readInt()
    val m = readInt()
    val uf = UF(m)

    val ans = mutableListOf<Int>()
    repeat(n) {
        val size = readInt()
        if (size == 1) {
            val a = readInt() - 1
            if (uf.activate(a)) {
                ans += it + 1
            }
        } else {
            val a = readInt() - 1
            val b = readInt() - 1
            if (uf.union(a, b)) {
                ans += it + 1
            }
        }
    }
    val v = modPow(2, ans.size, 1_000_000_007)
    println("$v ${ans.size}")
    println(ans.joinToString(" "))

}


private class UF(val n: Int) {
    val reps = IntArray(n) { it }
    val size = IntArray(n) { 1 }
    val activated = BooleanArray(n)

    fun find(a: Int): Int {
        var k = reps[a]
        while (reps[k] != k) {
            k = reps[k]
        }
        return k
    }

    fun activate(a: Int): Boolean {
        val u = find(a)
        return if (activated[u]) {
            false
        } else {
            activated[u] = true
            true
        }
    }

    fun union(a: Int, b: Int): Boolean {
        val u = find(a)
        val v = find(b)
        return if (u == v) {
            false
        } else if (activated[u] && activated[v]) {
            false
        } else {
            if (size[u] > size[v]) {
                size[u] += size[v]
                reps[v] = u
                activated[u] = activated[u] || activated[v]
            } else {
                size[v] += size[u]
                reps[u] = v
                activated[v] = activated[u] || activated[v]
            }
            true
        }
    }
}

private inline fun <T> tm(block: FIO.() -> T) {
    FIO().use(block)
}

private class FIO : AutoCloseable, PrintWriter(System.out.bufferedWriter(), false) {
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