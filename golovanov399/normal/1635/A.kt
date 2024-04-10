import kotlin.math.*

fun solve() {
    readLine()!!
    val a = readLine()!!.split(' ').map(String::toInt)
    println(a.reduce(Int::or))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}