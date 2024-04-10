import kotlin.math.*

class Heap<T : Comparable<T>> {
    private var a = mutableListOf<T>()

    val size: Int
        get() = a.size

    fun isEmpty(): Boolean {
        return a.size == 0
    }

    private fun swap(i: Int, j: Int) {
        val x = a[i]
        a[i] = a[j]
        a[j] = x
    }

    fun top(): T {
        return a[0]
    }

    private fun siftDown(idx: Int) {
        var nx = idx
        for (i in 1..2) {
            if (2 * idx + i < size && a[2 * idx + i] < a[nx]) {
                nx = 2 * idx + i
            }
        }
        if (nx != idx) {
            swap(nx, idx)
            siftDown(nx)
        }
    }

    fun pop() {
        a[0] = a[size - 1]
        a.removeLast()
        siftDown(0)
    }

    private fun siftUp(idx: Int) {
        if (idx == 0) {
            return
        }
        val nx = (idx - 1) / 2
        if (a[idx] < a[nx]) {
            swap(idx, nx)
            siftUp(nx)
        }
    }

    fun add(x: T) {
        a.add(x)
        siftUp(size - 1)
    }
}

data class Edge(val v: Int, val w: Long) : Comparable<Edge> {
    override operator fun compareTo(other: Edge): Int {
        return if (w != other.w) {
            if (w < other.w) -1 else 1
        } else {
            if (v < other.v) -1 else 1
        }
    }
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong).toLongArray()
    var g = List<MutableList<Edge>>(n) { mutableListOf() }
    repeat (m) {
        val line = readLine()!!.split(' ')
        val u = line[0].toInt() - 1
        val v = line[1].toInt() - 1
        val w = line[2].toLong()
        g[u].add(Edge(v, w))
        g[v].add(Edge(u, w))
    }

    val perm = IntArray(n) { it }.sortedWith(compareBy { a[it] })
    var used = BooleanArray(n) { false }
    var ans = 0L
    var ptr = 0
    used[perm[0]] = true
    var heap = Heap<Edge>()
    for (e in g[perm[0]]) {
        heap.add(e)
    }
    var curmin = a[perm[0]]
    repeat (n - 1) {
        while (ptr < n && used[perm[ptr]]) {
            ++ptr
        }
        while (!heap.isEmpty() && used[heap.top().v]) {
            heap.pop()
        }
        var opt = Edge(perm[ptr], a[perm[ptr]] + curmin)
        if (!heap.isEmpty() && heap.top() < opt) {
            opt = heap.top()
            heap.pop()
        }
        used[opt.v] = true
        curmin = min(curmin, a[opt.v])
        ans += opt.w
        for (e in g[opt.v]) {
            heap.add(e)
        }
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}