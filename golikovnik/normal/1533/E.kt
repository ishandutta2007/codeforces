fun solve() {
  val n = readInt()
  val a = readInts().sorted()
  val b = readInts().sorted()
  val pref = IntArray(n + 1) { Int.MIN_VALUE }
  for (i in a.indices) {
    pref[i + 1] = maxOf(pref[i], b[i] - a[i])
  }
  val suff = IntArray(n + 1) { Int.MIN_VALUE }
  for (i in a.indices.reversed()) {
    suff[i] = maxOf(suff[i + 1], b[i + 1] - a[i])
  }
  readInt()
  val answers = arrayListOf<Int>()
  for (x in readInts()) {
    var left = -1
    var right = n
    while (left + 1 != right) {
      val middle = (left + right) / 2
      if (a[middle] > x) {
        right = middle
      } else {
        left = middle
      }
    }
    answers.add(maxOf(pref[right], b[right] - x, suff[right]))
  }
  println(answers.joinToString(" "))
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