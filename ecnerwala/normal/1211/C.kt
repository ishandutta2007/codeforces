private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    var (n, k) = readLongs()
    val cnd = mutableListOf<Pair<Long, Long>>()
    var ans = 0L
    (0..n-1).forEach {
        val (a,b,c) = readLongs()
        ans += a * c
        k -= a
        cnd.add(c to (b-a))
    }

    if (k < 0) {
        outputLn("-1")
        return
    }

    cnd.sortBy { it.first }
    cnd.forEach {
        val amt = minOf(k, it.second)
        ans += amt * it.first
        k -= amt
    }

    if (k != 0L) {
        outputLn("-1")
    } else {
        outputLn("${ans}")
    }
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}