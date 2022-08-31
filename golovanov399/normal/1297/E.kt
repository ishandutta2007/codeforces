import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    var g = List(n) { mutableListOf<Int>() }
    for (i in 1 until n) {
        val (u, v) = readLine()!!.split(' ').map(String::toInt).map { it - 1 }
        g[u].add(v)
        g[v].add(u)
    }
    var deg = IntArray(n) { 0 }
    var cur = 1
    var q = mutableListOf(0)
    var used = BooleanArray(n) { false }
    used[0] = true
    var i = 0
    var j = 0
    if (k == 1) {
        println("Yes")
        println("1")
        println("1")
        return
    }
    while (i < q.size) {
        val u = q[i]
        val v = g[u][j]
        if (!used[v]) {
            if (deg[u] <= 1) {
                cur -= 1
            }
            deg[u] += 1
            deg[v] = 1
            cur += 1
            if (deg[u] <= 1) {
                cur += 1
            }
            used[v] = true
            q.add(v)
        }
        if (cur == k) {
            println("Yes")
            println(q.size)
            println(q.map { it + 1 }.joinToString(separator = " "))
            return
        }

        j += 1
        if (j == g[u].size) {
            i += 1
            j = 0
        }
    }

    println("No")
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}