import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    val ans = mutableListOf<Int>()
    for (i in n downTo 1) {
        val k = (a.indexOf(i) + 1) % i
        ans.add(k)
        a = a.subList(k, i) + a.take(k) + a.drop(i)
    }
    println(ans.reversed().joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}