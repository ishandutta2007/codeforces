import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    when {
        a.zipWithNext().all { (x, y) -> x <= y } -> {
            println(0)
        }
        a.first() == 1 || a.last() == n -> {
            println(1)
        }
        a.first() == n && a.last() == 1 -> {
            println(3)
        }
        else -> {
            println(2)
        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}