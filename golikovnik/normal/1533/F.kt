fun solve() {
  val s = readLn()
  val n = s.length
  val pref = IntArray(n + 1) { 0 }
  for (i in s.indices) {
    pref[i + 1] = pref[i] + (s[i] - '0')
  }

  fun findTake(k: Int, from: Int): Int {
    var left = from
    var right = n + 1
    while (left + 1 != right) {
      val middle = (left + right) / 2
      val len = middle - from
      val ones = pref[middle] - pref[from]
      val zeros = len - ones
      if (minOf(ones, zeros) > k) {
        right = middle
      } else {
        left = middle
      }
    }
    return left
  }

  fun solveEach(k: Int): Int {
    var left = 0
    var ans = 0
    while (left < n) {
      val take = findTake(k, left)
      left = take
      ans += 1
    }
    return ans
  }

  println((1..n).map {solveEach(it)}.joinToString(" "))
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