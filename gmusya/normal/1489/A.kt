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
  val arr = readInts()
  var used = BooleanArray(1001)
  val ans = arrayListOf<Int>()
  for (x in (n - 1) downTo 0) {
    val tmp = arr[x]
    if (used[tmp])
      continue;
    ans.add(tmp)
    used[tmp] = true
  }
  println(ans.size)
  for (x in (ans.size - 1) downTo 0)
    print("${ans[x]} ")
}