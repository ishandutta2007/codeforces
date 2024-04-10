private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    var v = readInt()
    val ans = mutableListOf<Int>()
    var p10 = 1
    while (v > 0) {
        if (v % 10 != 0) {
            ans.add(v % 10 * p10)
        }
        v /= 10
        p10 *= 10
    }
    outputLn("${ans.size}")
    outputLn(ans.joinToString(" "))
}

fun main() {
    val T = readInt()
    for (i in 1..T) go()
    println(OUTPUT_LINES.joinToString("\n"))
}