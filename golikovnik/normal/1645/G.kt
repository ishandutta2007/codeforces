import java.util.*

fun solve() {
  val n = readInt()
  val s = readLn().map { it - 'a' }
  val t = readLn().map { it - 'a' }
  val ans = Array(n) { 0 }
  for (i in 0 until n) {
    val sum = (s[i] + t[i])
    if (sum % 2 == 1) {
      ans[i+1] += 13
    }
    ans[i] += (s[i] + t[i]) / 2
  }
  ans.reverse()
  var carry = 0
  for (i in 0 until n) {
    ans[i] += carry
    carry = ans[i] / 26
    ans[i] %= 26
  }
  println(ans.reversed().map { 'a' + it }.joinToString(""))
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