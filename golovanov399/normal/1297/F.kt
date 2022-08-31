import kotlin.math.*
import kotlin.system.exitProcess

class Heap(_n: Int) {
    var n = 0
    private var a = IntArray(_n) { 0 }

    fun isEmpty(): Boolean {
        return n == 0
    }

    private fun swap(i: Int, j: Int) {
        val x = a[i]
        a[i] = a[j]
        a[j] = x
    }

    fun top(): Int {
        return a[0]
    }

    private fun siftDown(idx: Int) {
        var nx = idx
        for (i in 1..2) {
            if (2 * idx + i < n && a[2 * idx + i] < a[nx]) {
                nx = 2 * idx + i
            }
        }
        if (nx != idx) {
            swap(nx, idx)
            siftDown(nx)
        }
    }

    fun pop() {
        a[0] = a[n - 1]
        n -= 1
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

    fun add(x: Int) {
        a[n] = x
        n += 1
        siftUp(n - 1)
    }
}

data class Movie(val first: Int, val second: Int, val id: Int) {}

fun check(a: MutableList<Movie>, m: Int, off: Int): Boolean {
    var cur = 0
    var S = Heap(a.size)
    var i = 0
    while (i < a.size || !S.isEmpty()) {
        if (S.isEmpty()) {
            cur = a[i].first
        }
        while (i < a.size && a[i].first == cur) {
            S.add(a[i].second + off)
            i += 1
        }
        for (j in 0 until m) {
            if (S.isEmpty()) {
                break
            }
            val x = S.top()
            S.pop()
            if (x < cur) {
                return false
            }
        }
        cur += 1
    }
    return true
}

fun getTimes(a: MutableList<Movie>, m: Int, off: Int): MutableList<Int> {
    var cur = 0
    var S = Heap(a.size)
    var i = 0
    var M = mutableMapOf<Int, MutableList<Int>>()
    var N = mutableMapOf<Int, Int>()
    var ans = MutableList(a.size) { 0 }
    while (i < a.size || !S.isEmpty()) {
        if (S.isEmpty()) {
            cur = a[i].first
        }
        while (i < a.size && a[i].first == cur) {
            S.add(a[i].second + off)
            if (!M.containsKey(a[i].second + off)) {
                M[a[i].second + off] = mutableListOf()
                N[a[i].second + off] = 0
            }
            M[a[i].second + off]!!.add(a[i].id)
            i += 1
        }
        for (j in 0 until m) {
            if (S.isEmpty()) {
                break
            }
            val x = S.top()
            S.pop()
            ans[M[x]!![N[x]!!]] = cur
            N[x] = N[x]!! + 1
        }
        cur += 1
    }
    return ans
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var a = MutableList(n) { Movie(0, 0, 0) }
    for (i in a.indices) {
        val (x, y) = readLine()!!.split(' ').map(String::toInt)
        a[i] = Movie(x, y, i)
    }
    a.sortWith(compareBy { it.first })
    var l = -1
    var r = n + 1
    while (r > l + 1) {
        val mid = (l + r) / 2
        if (check(a, m, mid)) {
            r = mid
        } else {
            l = mid
        }
    }
    println(r)
    var tm = getTimes(a, m, r)
    println(tm.joinToString(separator = " "))
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}