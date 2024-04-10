import java.util.*

fun solve() {
  val (n, k) = readInts()
  val bits = PriorityQueue<Int>(reverseOrder())
  bits.addAll((0 until 30).filter { ((n shr it) and 1) == 1 }.map {1 shl it})
  while (bits.size < k) {
    val x = bits.poll()!!
    if (x == 1) {
      println("NO")
      return
    }
    bits.add(x / 2)
    bits.add(x / 2)
  }
  if (bits.size == k) {
    println("YES")
    println(bits.joinToString(" "))
  } else {
    println("NO")
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