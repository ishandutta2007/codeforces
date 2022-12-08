import java.util.Scanner

object CF551B extends App {
  var in = new Scanner(System.in)
  val n = in.nextInt()
  val a = (1 to n).map(i => in.nextInt())
  val b = a.map(i => a.count(j => j > i) + 1)
  println(b.mkString(" "))
}