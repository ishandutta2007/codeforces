private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go(): Boolean {
    val (x, y, z) = readInts()
    val (a, b, c) = readInts()

    return (x <= a) && (x + y <= a + b) && (x + y + z <= a + b + c)
}

fun main() {
    outputLn(if(go()) "YES" else "NO")
    println(OUTPUT_LINES.joinToString("\n"))
}