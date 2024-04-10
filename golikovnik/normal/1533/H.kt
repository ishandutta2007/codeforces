fun solve() {
  val (n, m) = readInts()
  val a = (0 until n).map { readLn() }

  fun solveSingle(mask: Int): Long {
    var ans = 0L
    val curH = IntArray(m)
    for (r in 0 until n) {
      for (c in 0 until m) {
        if (mask.hasBit(a[r][c] - 'A')) {
          curH[c]++
        } else {
          curH[c] = 0
        }
      }

      val prevSmaller = IntArray(m)
      for (i in 0 until m) {
        var k = i - 1
        while (k >= 0 && curH[k] >= curH[i]) {
          k = prevSmaller[k]
        }
        prevSmaller[i] = k
      }
      val lastOcc = IntArray(n + 1) { m }
      val nextSmaller = IntArray(m)
      val nextLE = IntArray(m)
      for (i in m - 1 downTo 0) {
        var k = i + 1
        while (k < m && curH[k] >= curH[i]) {
          k = nextSmaller[k]
        }
        nextSmaller[i] = k
        nextLE[i] = minOf(nextSmaller[i], lastOcc[curH[i]])
        lastOcc[curH[i]] = i
      }

      for (i in 0 until m) {
        ans += curH[i].toLong() * (i - prevSmaller[i]) * (nextLE[i] - i)
      }
    }

    return ans
  }

  val MASKS = 1 shl 5
  val submask = LongArray(MASKS) { solveSingle(it) }
  for (bit in 0 until 5) {
    for (mask in (MASKS - 1) downTo 0) {
      if (mask.hasBit(bit)) {
        submask[mask] -= submask[mask xor (1 shl bit)]
      }
    }
  }
  val ans = LongArray(6)
  for (mask in 0 until MASKS) {
    ans[Integer.bitCount(mask)] += submask[mask]
  }
  println(ans.drop(1).joinToString(" "))
}

fun Int.hasBit(b: Int): Boolean {
  return this and (1 shl b) != 0
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