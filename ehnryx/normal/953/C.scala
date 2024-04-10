object c extends App {
  import scala.io.StdIn._
  val n: Int = Integer.parseInt(readLine())
  val a: Array[Int] = readLine().split(" ").map(Integer.parseInt(_))

  var len: Int = 0
  for (i <- 0 until n) {
    val j: Int = i-1
    if (i > 0 && a(i) != a(j)) {
      len = 0
    }
    len += 1
  }

  var cur: Int = 1
  var bad = false
  for (i <- 1 until n) {
    val j: Int = i-1
    if (a(i) != a(j)) {
      if (cur != len) {
        bad = true
      }
      cur = 1
    } else {
      cur += 1
    }
  }

  if (cur != len || bad) {
    println("NO")
  } else {
    println("YES")
  }
}