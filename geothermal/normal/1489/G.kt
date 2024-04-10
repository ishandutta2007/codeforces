import java.io.PrintWriter
import java.util.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

class DisjointSetUnionByRank {
    private var totalSize: Int = 0
    private var subsetCount: Int = 0
    private var subsetSizes: IntArray
    private var parents: IntArray
    private var ranks: IntArray

    // O(n)
    constructor(size: Int) {
        if (size <= 0)
            throw IllegalArgumentException()

        this.totalSize = size
        this.subsetCount = size
        this.parents = IntArray(size)
        this.subsetSizes = IntArray(size)
        this.ranks = IntArray(size)
        for (node in 0 until size) {
            this.parents[node] = node
            this.subsetSizes[node] = 1
            this.ranks[node] = 0
        }
    }

    fun size(): Int = totalSize

    fun subsetCount(): Int = subsetCount

    // a(n)
    fun subsetSize(node: Int): Int {
        val root = find(node)
        return subsetSizes[root]
    }

    // a(n)
    fun connected(node1: Int, node2: Int): Boolean {
        return find(node1) == find(node2)
    }

    // a(n)
    fun find(findNode: Int): Int {
        if (findNode >= totalSize)
            throw IllegalAccessException()

        var node = findNode
        while (node != parents[node]) {
            node = parents[node]
        }
        val root = node

        // Path compression
        node = findNode
        while (node != root) {
            val nextNode = parents[node]
            parents[node] = root
            node = nextNode
        }

        return root
    }

    // a(n)
    fun union(node1: Int, node2: Int) {
        if (node1 >= totalSize || node2 >= totalSize)
            throw IllegalAccessException()

        var root1 = find(node1)
        var root2 = find(node2)

        if (root1 == root2)
            return

        // make sure root1 is bigger, swap if necessary
        if (ranks[root2] > ranks[root1]) {
            val temp = root2
            root2 = root1
            root1 = temp
        }

        // union by rank
        parents[root2] = root1
        subsetSizes[root1] += subsetSizes[root2]
        subsetSizes[root2] = 0
        subsetCount -= 1

        if (ranks[root2] == ranks[root1])
            ranks[root1] += 1
    }

}

class Edge : Comparable<Edge> {
    var A = 0
    var B = 0
    var W = 0L
    constructor(a : Int, b : Int, w : Long) {
        A = a
        B = b
        W = w
    }

    override operator fun compareTo(other: Edge) : Int {
        if (W < other.W) {
            return -1
        }
        if (W > other.W) return 1
        return 0
    }


}

fun main(args: Array<String>) {

    var (N, M) = readInts(2)
    var A = readLongArray(N)
    var best = 0
    for (i in 1 until N) {
        if (A[i] < A[best]) {
            best = i
        }
    }
    var ed = ArrayList<Edge>()
    for (i in 0 until N) {
        ed.add(Edge(i, best, A[i]+A[best]))
    }
    for (i in 0 until M) {
        var (X, Y) = readInts(2)
        X--
        Y--
        var W = readLong()
        ed.add(Edge(X, Y, W))
    }
    var dsu = DisjointSetUnionByRank(N)
    ed.sort()
    var ans = 0L
    for (i in 0 until ed.size) {
        if (!dsu.connected(ed[i].A, ed[i].B)) {
            dsu.union(ed[i].A, ed[i].B)
            ans += ed[i].W
        }
    }
    println(ans)



}