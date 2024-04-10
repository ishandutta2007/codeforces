import kotlin.math.*

fun solve() {
    val (l, r, a) = readLine()!!.split(' ').map(String::toInt)
    if (l / a == r / a) {
        println(r / a + r % a)
    } else {
        println(max(r / a + r % a, r / a - 1 + a - 1))
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}