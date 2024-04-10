import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m, d) = readLine()!!.split(' ').map(String::toInt)
    var c = readLine()!!.split(' ').map(String::toInt).toIntArray()
    var s = c.sum() + (d - 1) * (m + 1)
    if (s < n) {
        println("NO")
        return
    }
    var spaces = IntArray(m + 1) { d - 1 }
    for (i in 0..m) {
        val tmp = min(s - n, spaces[i])
        spaces[i] -= tmp
        s -= tmp
    }
    var str = mutableListOf<Int>()
    for (i in 0..m) {
        str.addAll(List(spaces[i]) { 0 })
        if (i < m) {
            str.addAll(List(c[i]) { i + 1 })
        }
    }
    println("YES")
    println(str.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}