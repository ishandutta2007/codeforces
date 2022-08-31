import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val pq = PriorityQueue<Int>()
    var bal = 0L
    for (x in a) {
        bal += x
        pq.add(x)
        while (bal < 0) {
            bal -= pq.remove()!!
        }
    }
    println(pq.size)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}