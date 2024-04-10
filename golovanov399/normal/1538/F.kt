import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (l, r) = readLine()!!.split(' ').map(String::toInt)
    var ans = 0L
    var tenPower = 1
    for (i in 0..9) {
        ans += (r / tenPower) - (l / tenPower)
        tenPower *= 10
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}