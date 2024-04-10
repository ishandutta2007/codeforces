private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val T = readInt()
    val output = mutableListOf<String>()
    for (t in 0..T-1) {
        val n = readInt()
        output += "${n/2}"
    }
    println(output.joinToString("\n"))
}