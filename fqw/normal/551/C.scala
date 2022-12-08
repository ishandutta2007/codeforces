import java.util.Scanner
import java.util.StringTokenizer

object CF551C extends App {
  var token = new StringTokenizer("")
  def next() = {
    while (!token.hasMoreTokens()) token = new StringTokenizer(readLine)
    token.nextToken()
  }

  val n = next.toInt
  val m = next.toLong
  val a = (1 to n).map(_ => next.toLong)

  def ok(timeLimit: Long): Boolean = {
    var um, rd: Long = 0
    for (i <- n - 1 to 0 by -1) {
      if (a(i) <= rd)
        rd -= a(i)
      else {
        val each = timeLimit - i - 1
        if (each <= 0)
          return false
        val need = a(i) - rd
        val take = (need - 1) / each + 1
        um += take
        rd = take * each - need
      }
    }
    um <= m
  }

  var (le, ri) = (0.toLong, 1e15.toLong)
  while (le < ri) {
    val mid = (le + ri) / 2;
    if (ok(mid))
      ri = mid
    else
      le = mid + 1
  }
  println(le)
}