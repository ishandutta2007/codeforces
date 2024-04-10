import java.util.Scanner
import scala.math
import scala.util.control.Breaks._
import java.lang.Exception

object CF551B extends App {
  //var in = new Scanner(System.in)
  val a = readLine()
  val b = readLine()
  val c = readLine()
  val ca = ('a' to 'z').map(x => a.count { y => x == y })
  val cb = ('a' to 'z').map(x => b.count { y => x == y })
  val cc = ('a' to 'z').map(x => c.count { y => x == y })
  var bestX = 0
  var bestY = 0
  try {
  for (x <- 0 to 100000) {
    var y = 100000
    for (i <- 0 to 25) {
      val tmp = ca(i) - cb(i) * x
      if (tmp < 0)
        y = -1
      else {
        if (cc(i) > 0)
          y = Math.min(y, tmp / cc(i))
      }
    }
    if (y < 0)
      throw new Exception()
    if (y >= 0 && x + y > bestX + bestY) {
      bestX = x
      bestY = y
    }
  }
  } catch {
    case _ =>
  }

  for (x <- 1 to bestX)
    print(b)
  for (y <- 1 to bestY)
    print(c)
  for (i <- 0 to 25) {
    val rest = ca(i) - cb(i) * bestX - cc(i) * bestY
    for (j <- 1 to rest)
      print((97 + i).toChar)
  }
}