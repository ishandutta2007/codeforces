import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).reversed()
    var res = mutableListOf<Int>()
    for (x in a) {
        if (!res.contains(x)) {
            res.add(x)
        }
    }
    res.reverse()
    println(res.size)
    println(res.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}