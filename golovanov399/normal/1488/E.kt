import kotlin.math.*

class Fenwick(private val n: Int) {
    private var a = MutableList(n) { 0 }

    fun remax(pos: Int, x: Int) {
        var i = pos
        while (i < n) {
            a[i] = max(a[i], x)
            i = i or (i + 1)
        }
    }

    fun get(pos: Int): Int {
        var res = 0
        var i = pos
        while (i >= 0) {
            res = max(res, a[i])
            i = (i and (i + 1)) - 1
        }
        return res
    }
}

fun solve() {
    val n = readLine()!!.toInt()
//    val n = 5
    val a = readLine()!!.split(' ').map(String::toInt)
//    val a = (2..(2*n+1)).map { x -> x / 2 }.shuffled().take(n)
//    println(a)
    val le = IntArray(n + 1) { n }
    val ri = IntArray(n + 1) { -1 }
    a.forEachIndexed { i, x ->
        le[x] = min(le[x], i)
        ri[x] = max(ri[x], i)
    }

    val vals = (1..n).filter { le[it] != ri[it] && ri[it] > -1 }.sortedBy { le[it] }
    val f = Fenwick(vals.size)
    val perm = vals.sortedBy { -ri[it] }
    val idx = IntArray(n + 1) { -1 }
    perm.forEachIndexed { i, x -> idx[x] = i }
    var ans = 1
    vals.forEach {
        val cur = f.get(idx[it]) + 1
        f.remax(idx[it], cur)
        ans = if (le[it] + 1 < ri[it])
            max(ans, 1 + 2 * cur)
        else
            max(ans, 2 * cur)
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}