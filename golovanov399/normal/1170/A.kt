import kotlin.math.max
import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}

fun solve() {
    var (x, y) = readLine()!!.split(' ').map(String::toInt)
    val z = min(x, y) - 1
    x -= z
    y -= z
    println("$z $x $y")
}