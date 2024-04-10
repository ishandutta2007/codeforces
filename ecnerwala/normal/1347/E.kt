import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val N = readInt()
    if (N <= 3) {
        outputLn("-1")
        return
    }
    val P = LinkedList(listOf(3, 1, 4, 2))
    for (i in 5..N) {
        if (i % 2 == 0) {
            P.add(i)
        } else {
            P.addFirst(i)
        }
    }

    outputLn(P.joinToString(" "))
}

fun main() {
    val T = readInt()
    for (i in 1..T) go()
    println(OUTPUT_LINES.joinToString("\n"))
}