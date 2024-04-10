import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var tests = readInt()
    while (tests-- > 0) {
        val (n, k) = readInts()
        println((1..n).map {
            val (l, r) = readInts()
            if (k in l..r) r - max(k, l) + 1 else 0
        }.maxOrNull())
    }
}