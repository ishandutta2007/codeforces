import java.util.*
import kotlin.math.*

data class Node(val cnt: Int, var upd: Int, var sum: Long)

class Segtree(_n: Int) {
    private val n = 1 shl (32 - (_n - 1).countLeadingZeroBits())
    private var a = MutableList(n + n) { Node(if (it == 0) 0 else n shr (31 - it.countLeadingZeroBits()), 0, 0L) }

    fun push(v: Int) {
        if (a[v].upd > 0) {
            for (t in 0..1) {
                a[v + v + t].upd = a[v].upd
                a[v + v + t].sum = a[v].upd * a[v + v + t].cnt.toLong()
            }
            a[v].upd = 0
        }
    }

    private fun upd(v: Int, l1: Int, r1: Int, l: Int, r: Int, x: Int) {
        if (l >= r1 || l1 >= r) {
            return
        }
        if (l <= l1 && r >= r1) {
            a[v].upd = x
            a[v].sum = x.toLong() * a[v].cnt
            return
        }
        push(v)
        val m = (l1 + r1) / 2
        upd(v + v, l1, m, l, r, x)
        upd(v + v + 1, m, r1, l, r, x)
        a[v].sum = a[v + v].sum + a[v + v + 1].sum
    }

    fun upd(l: Int, r: Int, x: Int) {
//        println("updating on [$l, $r) by $x")
        upd(1, 0, n, l, r, x)
    }

    private fun get(v: Int, l1: Int, r1: Int, l: Int, r: Int): Long {
        if (l >= r1 || l1 >= r) {
            return 0L
        }
        if (l <= l1 && r >= r1) {
            return a[v].sum
        }
        push(v)
        val m = (l1 + r1) / 2
        return get(v + v, l1, m, l, r) + get(v + v + 1, m, r1, l, r)
    }

    fun get(l: Int, r: Int): Long {
        return get(1, 0, n, l, r)
    }
}

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val q = readLine()!!.toInt()
    val qrs = MutableList(n) { mutableListOf<Pair<Int, Int>>() }
    for (i in 0 until q) {
        val (l, r) = readLine()!!.split(' ').map(String::toInt)
        qrs[r - 1].add(Pair(i, l - 1))
    }

    val tree = Segtree(n)
    val ans = MutableList (q) { 0L }

    val st = Stack<Int>()
    for (i in 0 until n) {
        while (!st.empty() && a[st.last()] <= a[i]) {
            st.pop()
        }
        val l = if (st.empty()) 0 else st.last() + 1
        tree.upd(l, i + 1, a[i])
        st.push(i)

        qrs[i].forEach { (idx, l) ->
            ans[idx] = tree.get(l, i + 1)
        }
    }

    println(ans.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}