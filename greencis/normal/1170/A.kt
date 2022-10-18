import java.util.*

fun main() { // fun is really main
    val sc = Scanner(System.`in`)
    val q = sc.nextLong()
    pyoslin@ for (ttt in 1..q) {
        var x = sc.nextLong()
        var y = sc.nextLong()
        if (x > y) {
            var t = x
            x = y
            y = t
        }
        var sum = x + y - 1
        var sa = x - 1
        var sb = y - 1
        var sc = 1L
        if (x <= y) {
            var ca = 1L
            var cb = x - ca
            var cc = y - cb
            if (ca + cb + cc < sum) {
                sum = ca + cb + cc
                sa = ca
                sb = cb
                sc = cc
            }
        }
        println(sa.toString() + " " + sb.toString() + " " + sc.toString())
    }
}