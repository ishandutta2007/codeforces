private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    var (y, b, r) = readInts()
    var v = minOf(y, b-1, r-2) * 3 + 3
    outputLn("${v}")
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}