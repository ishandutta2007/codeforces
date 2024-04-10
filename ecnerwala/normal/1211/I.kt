private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

private fun solveGroups(adj: List<List<Boolean>>): List<Int> {
    val N = adj.size

    val dist = List(N){i -> MutableList(N){j -> if (i == j) 0 else if (adj[i][j]) 1 else N+1 }}

    for (k in 0..N-1) {
        for (i in 0..N-1) {
            for (j in 0..N-1) {
                dist[i][j] = minOf(dist[i][j], dist[i][k] + dist[k][j])
            }
        }
    }

    val vis = MutableList(N){false}
    val queue = mutableListOf<Int>()

    for (start in 0..N-1) {
        if (!vis[start]) {
            var j = queue.size
            vis[start] = true;
            queue.add(start)
            while (j < queue.size) {
                val cur = queue[j]
                for (nxt in 0..N-1) {
                    if (vis[nxt]) continue
                    if (adj[cur][nxt]) {
                        vis[nxt] = true
                        queue.add(nxt)
                    }
                }
                j++
            }
        }
    }

    //println(adj)
    //println(queue)

    val resp = MutableList<Int>(N){0}

    fun recurse(ind: Int): Boolean {
        if (ind == N) {
            return true
        }
        val cur = queue[ind]
        valloop@ for (v in 0..16) {
            for (pind in 0..ind-1) {
                val d = v xor resp[queue[pind]]
                if (d == 0 || ((d and (d-1)) == 0) != adj[cur][queue[pind]]) {
                    continue@valloop
                }
            }
            resp[cur] = v
            if (recurse(ind+1)) {
                return true
            }
        }
        return false
    }

    recurse(0)

    return resp
}

private fun go() {
    val (N, M) = readInts()
    val adj = MutableList(N){MutableList(N){false}}
    for (i in 0..M-1) {
        val (u, v) = readInts()
        adj[u-1][v-1] = true
        adj[v-1][u-1] = true
    }

    val groupMap = mutableMapOf<MutableList<Boolean>, MutableList<Int>>()
    for (i in 0..N-1) {
        groupMap.getOrPut(adj[i], {mutableListOf<Int>()}).add(i)
    }

    val groups = groupMap.values.toList()
    val G = groups.size
    val groupAdj = List(G){ i -> List(G){ j -> adj[groups[i][0]][groups[j][0]] } }
    val groupColors = solveGroups(groupAdj)

    val A = MutableList(N){-1}
    for (g in 0..G-1) {
        for (v in groups[g]) {
            A[v] = groupColors[g]
        }
    }
    outputLn(A.joinToString(" "))
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}