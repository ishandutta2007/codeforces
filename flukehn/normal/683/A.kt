import java.util.Scanner
fun work(a: Int, x: Int, y: Int): Int {
    var ret =  if (a > x && a > y && x > 0 && y > 0) {
        0
    } else if (a >= x && a >= y && x >= 0 && y >= 0) {
        1
    } else {
        2
    }
    return ret
}
fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    var a: Int = read.nextInt()
    var x: Int = read.nextInt()
    var y: Int = read.nextInt()
    var ret = work(a, x, y)
    println("$ret")
}