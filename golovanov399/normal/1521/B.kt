import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val pos = a.indexOf(a.minOrNull()!!)
    println(n - 1)
    (0 until n).minus(pos).forEach {
        println("${it + 1} ${pos + 1} ${a[pos] + abs(it - pos)} ${a[pos]}")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}