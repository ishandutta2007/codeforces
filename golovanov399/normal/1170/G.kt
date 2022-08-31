import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var a = Array(n) {mutableListOf<Pair<Int, Int>>()}
    var ans = mutableListOf<MutableList<Int>>()
    var edges = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until m) {
        val (u, v) = readLine()!!.split(' ').map {it.toInt() - 1}
        edges.add(Pair(u, v))
        if (u == v) {
            ans.add(mutableListOf(u, v))
        } else {
            a[u].add(Pair(v, i))
            a[v].add(Pair(u, i))
        }
    }

    var ok = true
    for (i in 0 until n) {
        if (a[i].size % 2 == 1) {
            ok = false
        }
    }
    if (!ok) {
        println("NO")
        return
    }
    println("YES")

    val g = Array(n) {a[it].toTypedArray()}
    var usedEdge = Array(m) {false}
    var ptr = Array(n) {0}
    var cycle = mutableListOf<Int>()
    fun eulerCycle(u: Int) {
        while (ptr[u] < g[u].size && usedEdge[g[u][ptr[u]].second]) {
            ptr[u] += 1
        }
        if (ptr[u] == g[u].size) {
            return
        }
        val to = g[u][ptr[u]].first
        val id = g[u][ptr[u]].second
        usedEdge[id] = true
        eulerCycle(to)
        cycle.add(id)
        eulerCycle(u)
    }

    var used = Array(n) {false}
    for (i in 0 until n) {
        eulerCycle(i)
        if (cycle.isEmpty()) {
            continue
        }
        var st = Stack<Int>()
        st.add(i)
        used[i] = true
        var v = i
        for (id in cycle) {
            v = edges[id].first + edges[id].second - v
            if (used[v]) {
                ans.add(mutableListOf(v))
                while (st.last() != v) {
                    ans.last().add(st.last())
                    used[st.last()] = false
                    st.pop()
                }
                ans.last().add(v)
            } else {
                st.add(v)
                used[v] = true;
            }
        }
        used[i] = false
        cycle.clear()
    }

    println(ans.size)
    for (v in ans) {
        print(v.size)
        for (x in v) {
            print(" ${x+1}")
        }
        println()
    }
}