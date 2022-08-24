import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val b = readLine()!!.split(' ').map(String::toInt).sorted().reversed()
    var sum: Long = 0
    for (x in a) {
        sum += x
    }
    for (i in 0 until k) {
        if (b[i] > a[i]) {
            sum += b[i] - a[i]
        }
    }
    println(sum)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}