import java.util.*

fun solve() {
  val n = readInt()
  val a = readInts()
  val INF = 1e6.toInt()
  val dp = Array(n) { Array(2) { INF } }
  dp[0][0] = -INF
  dp[0][1] = -INF
  for (i in 1 until n) {
    for (sign in 0..1) {
      val x = a[i] * (1 - 2 * sign)
      val y = a[i - 1] * (1 - 2 * sign)
      if (x > y) {
        dp[i][sign] = dp[i - 1][sign]
      }
      if (x > dp[i - 1][1 - sign]) {
        dp[i][sign] = minOf(dp[i][sign], a[i - 1] * (2 * sign - 1))
      }
    }
  }
  if (dp[n - 1].minOf { it } == INF) {
    println("NO")
  } else {
    println("YES")
    var sign = (0..2).first { dp[n - 1][it] != INF}
    val ans = Array(n) { -1 }
    for (i in n-1 downTo 1) {
      ans[i] = sign
      val x = a[i] * (1 - 2 * sign)
      val y = a[i - 1] * (1 - 2 * sign)
      if (!(x > y && dp[i][sign] == dp[i - 1][sign])) {
        sign = 1 - sign
      }
    }
    ans[0] = sign
    println(ans.joinToString(" "))
  }
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