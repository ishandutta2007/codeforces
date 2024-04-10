import java.util.*

var inCycle = mutableListOf<Boolean>()
var visited = mutableListOf<Boolean>()
var distanceTo = mutableListOf<Int>()

fun read(): Graph {
    val reader = Scanner(System.`in`)
    val size = reader.nextInt()
    inCycle = MutableList(size) { false }
    visited = MutableList(size) { false }
    distanceTo = MutableList(size) { 0 }
    return Graph(size).apply {
        repeat(size, { addEdge(reader.nextInt(), reader.nextInt()) })
    }
}

fun markCycle(v: Int, graph: Graph, from: Int? = null): Int? {
    visited[v] = true
    graph.getEdgesFrom(v)
            .filter { to -> to != from }
            .forEach { to ->
                if (!visited[to]) {
                    val stop = markCycle(to, graph, v)
                    if (stop != null) {
                        inCycle[v] = true
                        return if (stop == v) null else stop
                    }
                } else {
                    inCycle[v] = true
                    return to
                }
            }
    return null
}

fun calcDist(v: Int, graph: Graph, from: Int? = null, distance: Int = 0) {
    distanceTo[v] = distance
    graph.getEdgesFrom(v)
            .filter { to -> to != from && !inCycle[to] }
            .forEach { to -> calcDist(to, graph, v, distance + 1) }
}

fun solve(graph: Graph): MutableList<Int> {
    markCycle(0, graph)
    (0 until graph.size)
            .filter { inCycle[it] }
            .forEach { calcDist(it, graph) }
    return distanceTo
}

fun main(args: Array<String>) {
    println(solve(read()).joinToString(separator = " "))
}

class Graph(val size: Int) {
    private val edges = MutableList(size) { mutableListOf<Int>() }

    fun addEdge(from: Int, to: Int) {
        edges[from - 1].add(to - 1)
        edges[to - 1].add(from - 1)
    }

    fun getEdgesFrom(v: Int) = edges[v]

}