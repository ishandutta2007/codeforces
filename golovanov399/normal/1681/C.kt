fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt).toMutableList()
    val b = readLine()!!.split(" ").map(String::toInt).toMutableList()
    val res = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until n) {
        val j = (i until n).map { it to (a[it] to b[it]) }.minWithOrNull(compareBy({ it.second.first }, { it.second.second }))!!.first
        if (j > i) {
            res.add(i to j)
            a[i] = a[j].also { a[j] = a[i] }
            b[i] = b[j].also { b[j] = b[i] }
        }
    }
    if (b == b.sorted()) {
        println(res.size)
        res.forEach { println("${it.first + 1} ${it.second + 1}") }
    } else {
        println(-1)
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}