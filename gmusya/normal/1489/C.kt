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
  val n = readInt()
  val s = readString()
  var ans = 0
  for (i in 2..(n - 1))
    if (s[i] == 'x' && s[i - 1] == 'x' && s[i - 2] == 'x')
      ans++
  print(ans)
}