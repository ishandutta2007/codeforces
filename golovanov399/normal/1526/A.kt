import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val ans = mutableListOf<Int>()
    for (i in 0 until n) {
        ans.add(a[i])
        ans.add(a[i + n])
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}