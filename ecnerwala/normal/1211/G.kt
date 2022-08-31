private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

private fun go() {
    val n = readInt()
    val c = readInts()
    val d = readInts()
    val adj = MutableList<MutableList<Int>>(n) {mutableListOf()}
    (1..n-1).forEach {
        val (x,y) = readInts()
        adj[x-1].add(y-1)
        adj[y-1].add(x-1)
    }

    if (c.sorted() != d.sorted()) {
        outputLn("No")
        return
    }

    if (c == d) {
        outputLn("Yes")
        outputLn("0")
        return
    }

    val alive = MutableList<Boolean>(n) {true}
    val deg = adj.map{it.size}.toMutableList()

    val q = mutableListOf<Int>()

    (0..n-1).forEach {
        if (c[it] == d[it] && deg[it] == 1) {
            q.add(it)
        }
    }

    while (q.size > 0) {
        val i = q.removeAt(q.size - 1)
        alive[i] = false
        for (j in adj[i]) {
            if (!alive[j]) {
                continue
            }
            deg[j] = deg[j] - 1
            if (c[j] == d[j] && deg[j] == 1) {
                q.add(j)
            }
        }
    }

    val alives = alive.mapIndexed{ind, v -> ind to v}.filter{it.second}.map{it.first}

    val endPts = alives.filter{deg[it] == 1}
    if (endPts.size != 2) {
        outputLn("No")
        return
    }

    (0..n-1).forEach {
        adj[it] = adj[it].filter{alive[it]}.toMutableList()
    }

    val (st, en) = endPts

    var path = mutableListOf<Int>()

    path.add(st)

    var prv = st
    var cur = adj[st][0]
    while (cur != en) {
        path.add(cur)
        val nxt = adj[cur][0] xor adj[cur][1] xor prv
        prv = cur
        cur = nxt
    }
    path.add(en)

    val c1 = mutableListOf<Int>().apply {addAll(c)}
    for (i in 0..path.size - 2) {
        val a = path[i]
        val b = path[i+1]
        val x = c1[a]
        val y = c1[b]
        c1[a] = y
        c1[b] = x
    }
    if (c1 == d) {
        outputLn("Yes")
        outputLn("${path.size}")
        outputLn(path.map{it+1}.joinToString(" "))
        return
    }

    path = path.asReversed()

    val c2 = mutableListOf<Int>().apply {addAll(c)}
    for (i in 0..path.size - 2) {
        val a = path[i]
        val b = path[i+1]
        val x = c2[a]
        val y = c2[b]
        c2[a] = y
        c2[b] = x
    }
    if (c2 == d) {
        outputLn("Yes")
        outputLn("${path.size}")
        outputLn(path.map{it+1}.joinToString(" "))
        return
    }
    outputLn("No")
}

fun main() {
    val T = readInt()
    (1..T).forEach {go()}
    println(OUTPUT_LINES.joinToString("\n"))
}