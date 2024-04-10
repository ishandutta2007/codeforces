private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (N, Morig) = readInts()
    val edges = mutableListOf<Pair<Int, Int>>()

    val cycles = mutableListOf<MutableList<Int>>()

    for (i in 0..Morig-1) {
        val (x, y) = readInts()
        edges += (x-1) to (y-1)
    }

    val adj = List<MutableList<Pair<Int, Int>>>(N, {mutableListOf()})

    val M = edges.size
    for (i in 0..M-1) {
        val (x, y) = edges[i]
        adj[x] += (y to i)
        adj[y] += (x to i)
    }

    for (i in 0..N-1) {
        if (adj[i].size % 2 == 1) {
            outputLn("NO")
            return
        }
    }

    val used = MutableList<Boolean>(M, {false})

    val path = mutableListOf<Int>()
    val inPath = MutableList<Boolean>(N, {false})

    for (i in 0..N-1) {
        var cur = i
        bigLoop@ while (true) {
            if (inPath[cur]) {
                val cyc = mutableListOf(cur)
                while (path[path.size - 1] != cur) {
                    val n = path[path.size - 1]
                    path.removeAt(path.size - 1)
                    inPath[n] = false
                    cyc += n
                }
                cyc += cur
                cycles += cyc
            } else {
                path += cur
                inPath[cur] = true
            }

            while (true) {
                if (adj[cur].isEmpty()) {
                    assert(cur == i)
                    break@bigLoop
                }
                val (nxt, e) = adj[cur][adj[cur].size - 1]
                adj[cur].removeAt(adj[cur].size - 1)
                if (used[e]) {
                    continue
                }
                used[e] = true
                cur = nxt
                break
            }
        }
        assert(path.size == 1)
        path.removeAt(0)
        inPath[i] = false
    }

    outputLn("YES")
    outputLn("${cycles.size}")
    for (c in cycles) {
        outputLn("${c.size} ${c.map({it + 1}).joinToString(" ")}")
    }
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}