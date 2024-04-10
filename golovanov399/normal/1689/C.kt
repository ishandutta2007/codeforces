import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = List(n) { mutableListOf<Int>() }
    repeat (n - 1) {
        val (u, v) = readLine()!!.split(" ").map { it.toInt() - 1 }
        a[u].add(v)
        a[v].add(u)
    }
    fun rec(v: Int, p: Int): Pair<Int, Int> {
        val sons = mutableListOf<Pair<Int, Int>>()
        for (x in a[v]) {
            if (x != p) {
                sons.add(rec(x, v))
            }
        }
        if (sons.isEmpty()) {
            return 1 to 0
        }
        if (sons.size == 1) {
            return (sons[0].first + 1) to sons[0].first - 1
        }
        return (sons[0].first + sons[1].first + 1) to max(sons[0].first - 1 + sons[1].second, sons[0].second + sons[1].first - 1)
    }
    println(rec(0, -1).second)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}