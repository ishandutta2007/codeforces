private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val M = readInt()
    val B = readInts()
    val N = B.count({it == -1})
    val A = MutableList<MutableList<Int>>(N, {mutableListOf()})

    var alive = MutableList<Int>(N, {it})

    var i = 0
    while (i < M) {
        var nalive = mutableListOf<Int>()
        for (j in alive) {
            val v = B[i]
            i++
            if (v == -1) {
                // noop
            } else {
                A[j].add(v)
                nalive.add(j)
            }
        }
        alive = nalive
    }

    outputLn("${N}")
    for (l in A) {
        outputLn("${l.size} ${l.joinToString(" ")}")
    }
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}