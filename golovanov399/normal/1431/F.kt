import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

class Heap(_n: Int) {
    var n = 0
    private var a = IntArray(_n) { 0 }

    fun isEmpty(): Boolean {
        return n == 0
    }

    fun clear() {
        n = 0
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
            if (2 * idx + i < n && a[2 * idx + i] > a[nx]) {
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
        if (a[idx] > a[nx]) {
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

fun solve() {
    val (n, k, x) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt)

    var h = Heap(x)
    fun check(maxw: Long): Boolean {
        var can = k
        var i = 0
        while (i < n) {
            var w = 0L
            h.clear()
            repeat(x) {
                if (i < n) {
                    h.add(a[i])
                    w += a[i]
                    i += 1
                }
            }
            while (w > maxw) {
                if (can == 0) {
                    return false
                }
                can -= 1
                w -= h.top()
                h.pop()
                if (i < n) {
                    h.add(a[i])
                    w += a[i]
                    i += 1
                }
            }
        }
        return true
    }

    var l = -1L
    var r = 1_000_000_000_000_000L
    while (r > l + 1) {
        val w = (l + r) / 2
        if (check(w)) {
            r = w
        } else {
            l = w
        }
    }
    println(r)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}