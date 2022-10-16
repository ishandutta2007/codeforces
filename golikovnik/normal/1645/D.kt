fun solve() {
  val n = readInt()
  val ans = Array(3) { ArrayList<Int>() }
  readInts().groupBy { it }.forEach { it.value.indices.forEach { jt -> ans[minOf(2, jt)].add(it.key) }}
  if (ans[2].isNotEmpty()) {
    println("NO")
  } else {
    println("YES")
    println(ans[0].size)
    println(ans[0].sorted().joinToString(" "))
    println(ans[1].size)
    println(ans[1].sortedDescending().joinToString(" "))
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