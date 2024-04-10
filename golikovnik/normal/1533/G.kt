fun solve() {
  val (n, m) = readInts()
  val ids = (0 until n).map { readInts() }
  var cnt = 0
  for (i in 0 until n) {
    for (j in 0 until m) {
      if (ids[i][j] > 0) {
        cnt += 1
      }
    }
  }
  val DX = IntArray(4)
  DX[0] = -1
  DX[1] = 0
  DX[2] = 1
  DX[3] = 0
  val DY = IntArray(4)
  DY[0] = 0
  DY[1] = 1
  DY[2] = 0
  DY[3] = -1

  val was = Array(n) { BooleanArray(m) }

  var nvis = 0
  val dfsOrder = arrayListOf<Int>()
  fun dfs(r: Int, c: Int) {
    dfsOrder.add(ids[r][c])
    was[r][c] = true
    nvis += 1
    for (i in 0 until 4) {
      val rr = r + DX[i]
      val cc = c + DY[i]
      if (0 <= rr && rr < n && 0 <= cc && cc < m && !was[rr][cc] && ids[rr][cc] != 0) {
        dfs(rr, cc)
        dfsOrder.add(ids[r][c])
      }
    }
  }

  for (i in 0 until n) {
    for (j in 0 until m) {
      if (ids[i][j] == 0) {
        continue
      }
      dfs(i, j)
      if (nvis != cnt) {
        println(-1)
        return
      }

      println("$cnt $cnt")
      for (start in 0 until cnt) {
        println(dfsOrder.subList(start, start + cnt).joinToString(" "))
      }
      return
    }
  }
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