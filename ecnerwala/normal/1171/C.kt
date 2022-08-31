private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val S = readLn().toCharArray()
    S.sort()
    if (S contentEquals S.reversedArray()) {
        outputLn("-1")
    } else {
        outputLn("${S.joinToString("")}")
    }
}

fun main() {
    val T = readInt()
    for (t in 1..T) { go() }
    println(OUTPUT_LINES.joinToString("\n"))
}