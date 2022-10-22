import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var T = readInt()

    for (test in 1..T) {
        val N = readInt()
        val (a, va) = readInts()
        val (c, vc) = readInts()
        val b = readInt()

        println(min(vc, b - a + va))
    }
}