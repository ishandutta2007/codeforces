private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    readInt()
    val vals = sortedMapOf<Int, Int>()
    readInts().forEachIndexed { ind, v -> vals[v] = ind+1 }
    val inds = vals.values.toList()
    if (inds.size >= 3) {
        outputLn("${inds[0]} ${inds[1]} ${inds[2]}")
    } else {
        outputLn("${-1} ${-1} ${-1}")
    }
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}