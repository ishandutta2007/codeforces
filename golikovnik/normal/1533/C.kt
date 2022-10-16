fun solve() {
  val (n, k) = readInts()
  val s = readLn()
  var count = s.count { it == '1' }
  var ans = 0
  val alive = BooleanArray(n) { true }
  var ptr = 0
  
  fun eat(i: Int) {
    alive[i] = false
    ans += 1
    if (s[i] == '1') {
      count -= 1
    }
  }
  
  while (count > 0) {
    eat(ptr)
    if (count == 0) break
    ptr += 1
    ptr %= n
    var need = k - 1
    while (need > 0) {
      if (alive[ptr]) {
        need -= 1
      }
      ptr += 1
      ptr %= n
    }
    while (!alive[ptr]) {
      ptr += 1
      ptr %= n
    }
  }
  println(ans)
}

fun main() {
  repeat(readInt()) {
    solve()
  }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles