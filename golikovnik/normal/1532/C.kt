fun solve() {
    val (n, k) = readInts()
    for (i in 0 until k) {
        for (j in 0 until n / k + (if (i < n % k) 1 else 0)) {
            print('a' + i)
        }
    }
    println()
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles