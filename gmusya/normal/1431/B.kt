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
    val s = readString()
    var ans = 0
    var last = -1
    for (i in s.indices) {
      if (s[i] == 'w') {
        ans++
        last = i
      } else {
        if (last + 1 < i) {
          last = i
          ans++
        }
      }
    }
    println(ans)
  }
}