private fun readTree(n: Int): Array<IntArray> {
    val edgesLefts = IntArray(n - 1)
    val edgeRights = IntArray(n - 1)
    val sizes = IntArray(n)
    for (i in 0 until n - 1) {
        val (u, v) = readLine()!!.split(" ").map { it.toInt() - 1 }
        edgesLefts[i] = u
        edgeRights[i] = v
        sizes[u]++
        sizes[v]++
    }
    val cons = Array(n) { i -> IntArray(sizes[i]) }
    sizes.fill(0)
    for (i in 0 until n - 1) {
        val u = edgesLefts[i]
        val v = edgeRights[i]
        cons[u][sizes[u]++] = v
        cons[v][sizes[v]++] = u
    }
    return cons
}

fun main() {
    val n = readLine()!!.toInt()
    val cons = readTree(n)
    println("d 1")
    val goalDepth = readLine()!!.toInt()
    val childrenOfCorrectDepth = IntArray(n)
    val depths = IntArray(n)
    val relevantChildren = Array(n) { mutableListOf<Int>() }
    fun dfs(node: Int, parent: Int) {
        if (depths[node] == goalDepth) childrenOfCorrectDepth[node]++
        for (child in cons[node]) {
            if (child != parent) {
                depths[child] = depths[node] + 1
                dfs(child, node)
                if (childrenOfCorrectDepth[child] != 0) {
                    childrenOfCorrectDepth[node] += childrenOfCorrectDepth[child]
                    relevantChildren[node].add(child)
                }
            }
        }
        relevantChildren[node].sortByDescending { childrenOfCorrectDepth[it] }
    }
    dfs(0, -1)
    val path = IntArray(goalDepth + 1)
    val baseIndex = IntArray(n)
    var cur = 0
    while (depths[cur] != goalDepth && childrenOfCorrectDepth[cur] == childrenOfCorrectDepth[relevantChildren[cur][baseIndex[cur]]]) {
        cur = relevantChildren[cur][baseIndex[cur]]
        path[depths[cur]] = cur
    }
    while (depths[cur] != goalDepth ) {
        if (childrenOfCorrectDepth[relevantChildren[cur][baseIndex[cur]]] * 2 > childrenOfCorrectDepth[cur]) {
            for (depth in depths[cur] + 1..goalDepth) {
                cur = relevantChildren[cur][baseIndex[cur]]
                path[depth] = cur
            }
            println("d ${cur + 1}")
            val dist = readLine()!!.toInt()
            if (dist != 0) {
                val splitDepth = goalDepth - (dist shr 1)
                cur = path[splitDepth]
                childrenOfCorrectDepth[cur] -= childrenOfCorrectDepth[relevantChildren[cur][baseIndex[cur]++]]
                while (relevantChildren[cur].isNotEmpty() && childrenOfCorrectDepth[cur] == childrenOfCorrectDepth[relevantChildren[cur][baseIndex[cur]]]) {
                    cur = relevantChildren[cur][baseIndex[cur]]
                    path[depths[cur]] = cur
                }
            }
        } else {
            println("s ${cur + 1}")
            cur = readLine()!!.toInt() - 1
            path[depths[cur]] = cur
            while (depths[cur] != goalDepth && childrenOfCorrectDepth[cur] == childrenOfCorrectDepth[relevantChildren[cur][baseIndex[cur]]]) {
                cur = relevantChildren[cur][baseIndex[cur]]
                path[depths[cur]] = cur
            }
        }
    }
    println("! ${cur + 1}")
}