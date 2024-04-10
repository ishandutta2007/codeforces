fun solve() {
  val n = readInt()
  val xs = readInts()
  println(if (xs.windowed(2).any { (it[1] - it[0]) % 2 == 0 }) "YES" else "NO")
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