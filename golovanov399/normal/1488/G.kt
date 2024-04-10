import java.util.*
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

operator fun Pair<Int, Int>.compareTo(other: Pair<Int, Int>): Int {
    return if (first != other.first) {
        if (first < other.first) -1 else 1
    } else if (second != other.second) {
        if (second < other.second) -1 else 1
    } else {
        0
    }
}

data class Shit(val value: Int, val idx: Int): Comparable<Shit> {
    override operator fun compareTo(other: Shit): Int {
        return if (value != other.value) {
            -value.compareTo(other.value)
        } else {
            idx.compareTo(other.idx)
        }
    }
}

fun solve() {
    val n = readLine()!!.toInt()

    val divs = MutableList(n + 1) { mutableListOf<Int>() }
    for (i in 1..n) {
        for (j in i..n step i) {
            divs[j].add(i)
        }
    }

    val taken = MutableList(n + 1) { false }
    val rem = MutableList(n + 1) { if (it > 0) n / it else 0 }

    val h = TreeSet<Shit>()
    for (i in 1..n) {
        h.add(Shit(n / i - divs[i].size, i))
    }
    val ans = mutableListOf<Int>()
    repeat (n - 1) {
        val (value, i) = h.first()
//        println("$i: $value")
        h.remove(h.first())
        ans.add(value)
        taken[i] = true
        for (d in divs[i]) {
            if (!taken[d]) {
                h.remove(Shit(rem[d] - divs[d].size, d))
                rem[d] -= 1
                h.add(Shit(rem[d] - divs[d].size, d))
            }
        }
    }
    println(ans.scan(0L, { x: Long, y: Int -> x + y.toLong() }).reversed().joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}