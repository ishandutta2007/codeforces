import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

const val inf = 1e9.toInt()

data class Edge(val from: Int, val to: Int, val cap: Int, var flow: Int, val cost: Int) {
    operator fun plusAssign(f: Int) {
        flow += f
    }
}

class Network(_n: Int) {
    private val n = _n
    private val edges = mutableListOf<Edge>()
    private val out = MutableList(n) { mutableListOf<Int>() }

    fun addEdge(from: Int, to: Int, cap: Int, cost: Int) {
        out[from].add(edges.size)
        edges.add(Edge(from, to, cap, 0, cost))
        out[to].add(edges.size)
        edges.add(Edge(to, from, 0, 0, -cost))
    }

    private fun findFlow(from: Int, to: Int): Pair<Int, Int> {
        val d = MutableList(n) { inf }
        val p = MutableList(n) { -1 }
        val q = mutableListOf<Int>()
        q.add(from)
        var start = 0
        val inQueue = MutableList(n) { false }
        d[start] = 0
        while (start < q.size) {
            val v = q[start]
            start += 1
            inQueue[v] = false
            out[v].filter { i -> edges[i].flow < edges[i].cap }.forEach { i ->
                val e = edges[i]
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost
                    p[e.to] = i
                    if (!inQueue[e.to]) {
                        q.add(e.to)
                        inQueue[e.to] = true
                    }
                }
            }
        }
        if (d[to] == inf) {
            return Pair(0, 0)
        }

        var flow = inf
        var cost = 0
        var v = to
        while (v != from) {
            val e = edges[p[v]]
            flow = min(flow, e.cap - e.flow)
            cost += e.cost
            v = e.from
        }
        v = to
        while (v != from) {
            edges[p[v]] += flow
            edges[p[v] xor 1] += -flow
            v = edges[p[v]].from
        }
        return Pair(flow, cost)
    }

    fun minCostMaxFlow(from: Int, to: Int): Int {
        var ans = 0
        while (true) {
            val (flow, cost) = findFlow(from, to)
            if (flow == 0) {
                break
            }
            ans += flow * cost
        }
        return ans
    }
}

fun solve() {
    val (nL, nR, m) = readLine()!!.split(' ').map(String::toInt)
    val ks = readLine()!!.split(' ').map(String::toInt)
    val net = Network(nL + nR + 2)
    val right = MutableList(nR) { mutableListOf<Int>() }
    repeat (m) {
        val (l, r) = readLine()!!.split(' ').map(String::toInt)
        right[r - 1].add(l - 1)
        net.addEdge(l, nL + r, 1, 0)
    }
    for (i in 1..nL) {
        net.addEdge(0, i, 1, 0)
    }
    for (i in 1..nR) {
        net.addEdge(nL + i, nL + nR + 1, right[i - 1].size - 1, 0)
        net.addEdge(nL + i, nL + nR + 1, 1, right[i - 1].minOfOrNull { ks[it] }!!)
    }
    println(net.minCostMaxFlow(0, nL + nR + 1))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}