fun solve() {
  val (n, m) = readInts()
  val cnt = mutableMapOf<String, Int>()
  repeat(n) {
    val s = readLn()
    cnt[s] = (cnt[s] ?: 0) + 1
  }
  repeat(readInt()) {
    val s = readLn()
    val all = mutableSetOf<String>()
    s.indices.forEach {
      all.add(s.substring(0, it) + s.substring(it + 1))
    }
    println(all.sumBy { cnt.getOrDefault(it, 0) })
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