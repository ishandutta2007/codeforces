/**
 * Created by ezhang on 5/28/19.
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args : Array<String>) {
    val q = readInt();
    for (i in 1..q) {
        val (a, b) = readInts()
        val x = minOf(a, b) - 1
        println("$x ${a - x} ${b - x}")
    }
}