import java.util.*

fun solve() {
  val n = readInt()
  val a = readInts().sorted()
  var last = -1
  var ans = 0
  for (x in a) {
    (x-1..x+1).firstOrNull { it > 0 && it > last } ?. let { last = it; ans++ }
  }
  println(ans)
}

fun main() {
//  repeat(readInt()) {
    solve()
//  }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles