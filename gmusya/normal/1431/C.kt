private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readString() = readLn().toString() // single line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
  val t = readInt()
  for (it in 0 until t) {
    val (n, k) = readInts()
    val arr = readInts()
    var ans = 0
    for (len in 1..n) {
      var sum = 0
      for (i in (n - len) until (n - len + len / k))
        sum += arr[i]
      ans = maxOf(sum, ans)
    }
    println(ans)
  }
}