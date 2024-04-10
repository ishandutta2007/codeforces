object Main extends AlgoApp {
  type Mat = (Long, Long, Long, Long)
  def multiply(a: Mat, b: Mat, modNum: Long): Mat = {
    ((a._1 * b._1 + a._2 * b._3) % modNum,
      (a._1 * b._2 + a._2 * b._4) % modNum,
      (a._3 * b._1 + a._4 * b._3) % modNum,
      (a._3 * b._2 + a._4 * b._4) % modNum)
  }
  def power(a: Mat, b: Long, modNum: Long): Mat = {
    var tmp = a
    var ans: Mat = (1L, 0L, 0L, 1L)
    var p = b
    while (p > 0) {
      if (p % 2 == 1) {
        ans = multiply(ans, tmp, modNum)
      }
      tmp = multiply(tmp, tmp, modNum)
      p >>= 1
    }
    ans
  }

  def solve(n: Long, res: Long, modNum: Long): Long = {
    val mat = power((1L, 1L, 1L, 0L), n, modNum)
    val ans = (mat._1 + mat._2) % modNum
    if (res == 0) {
      ans
    } else {
      var (x, y, z) = (2L, n, 1L)
      while (y > 0) {
        if (y % 2 == 1)
          z = z * x % modNum
        x = x * x % modNum
        y >>= 1
      }
      (z - ans + modNum) % modNum
    }
  }

  val n = nextLong
  var k = nextLong
  val l = nextInt
  val modNum = nextLong
  var ans = 1L % modNum
  for (i <- 1 to l) {
    val tmp = solve(n, k & 1, modNum)
    ans = ans * tmp % modNum
    k >>= 1
  }
  if (k > 0) ans = 0
  println(ans)
}

abstract class AlgoApp extends App {
  import java.util.StringTokenizer

  var token = new StringTokenizer("")
  def next = {
    while (!token.hasMoreTokens())
      token = new StringTokenizer(readLine)
    token.nextToken()
  }
  def nextInt = next.toInt
  def nextLong = next.toLong
}