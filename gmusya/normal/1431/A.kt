private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
  val t = readInt()
  for (it in 1..t) {
    val n = readInt()
    val arr = readLongs()
    var ans: Long = 0
    for (i in 0 until n) {
      var cnt: Int = 0
      for (j in 0 until n)
        if (arr[j] >= arr[i])
          cnt++
      ans = maxOf(ans, arr[i] * cnt)
    }
    println(ans)
  }
}