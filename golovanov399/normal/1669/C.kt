import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var ok = true
    for (i in 0 until n) {
        if (a[i] % 2 != a[i % 2] % 2) {
            ok = false
        }
    }
    println(if (ok) "YES" else "NO")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}