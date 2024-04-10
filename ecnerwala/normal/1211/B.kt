private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val n = readInt()
    val ans = readLongs().mapIndexed {
        ind, a -> (a-1) * n + ind + 1
    }.max()
    outputLn("${ans}")
}

fun main() {
    go()
    println(OUTPUT_LINES.joinToString("\n"))
}