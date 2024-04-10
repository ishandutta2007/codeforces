fun solve() {
  readInt()
  println(readInts().withIndex().groupBy { it.value }.minByOrNull { it.value.size }!!.value[0].index + 1)
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