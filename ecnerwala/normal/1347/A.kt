private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val T = readInt()
    for (case in 0..T-1) {
        val (a, b) = readInts()
        outputLn("${a+b}")
    }
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}