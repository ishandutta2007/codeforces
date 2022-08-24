import kotlin.math.*

data class Point(val id: Int, val x: Int, val w: Int)

fun solve() {
    readLine()
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val pts = (0 until m).map {
        val (x, y) = readLine()!!.split(' ').map(String::toInt)
        Point(it + 1, x, y)
    }.sortedBy { it.w }.take(2 * n).sortedBy { it.x }
    println(pts.sumOf { it.w })
    for (i in 0 until n) {
        println("${pts[i].id} ${pts[2 * n - 1 - i].id}")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}