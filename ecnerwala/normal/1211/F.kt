private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val n = readInt()
    val adj = MutableList<MutableList<Pair<Int, Int>>>(6) {mutableListOf()}
    (1..n).forEach{
        val s = readLn()
        val a = "kotlin".indexOf(s[0])
        val b = (a + s.length) % 6
        adj[b].add(a to it)
    }

    val ans = mutableListOf<Int>()
    fun recurse(cur: Int) {
        while (adj[cur].size > 0) {
            val (nxt, e) = adj[cur].removeAt(adj[cur].size - 1)
            recurse(nxt)
            ans.add(e)
        }
    }
    recurse(0)

    outputLn(ans.joinToString(" "))
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}