import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    when {
        n % 3 == 0 -> {
            println(List(n / 3) { "21" }.joinToString(""))
        }
        n % 3 == 1 -> {
            println("1" + List(n / 3) { "21" }.joinToString(""))
        }
        n % 3 == 2 -> {
            println("2" + List(n / 3) { "12" }.joinToString(""))
        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}