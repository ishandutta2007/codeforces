
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    var (x, y) = readLongs()
    x -= 2
    y -= 2
    var z = maxOf(x, y) - minOf(x, y)
    var s = (x + y + z) / 2
    val a = s - x
    val b = s - y
    val c = s - z
    outputLn("${a+1} ${b+1} ${c+1}")
}

fun main() {
    val T = readInt()
    for (t in 1..T) { go() }
    println(OUTPUT_LINES.joinToString("\n"))
}