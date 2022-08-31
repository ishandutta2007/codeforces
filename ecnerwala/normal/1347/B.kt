private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    var (a1, b1) = readInts().sorted()
    if (a1 > b1) a1 = b1.also { b1 = a1 }
    var (a2, b2) = readInts().sorted()
    if (a2 > b2) a2 = b2.also { b2 = a2 }
    outputLn(if (b1 == b2 && a1 + a2 == b1) "Yes" else "No")
}

fun main() {
    val T = readInt()
    for (case in 0..T-1) {
        go()
    }
    println(OUTPUT_LINES.joinToString("\n"))
}