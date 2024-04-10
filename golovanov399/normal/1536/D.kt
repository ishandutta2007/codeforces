import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val b = readLine()!!.split(' ').map(String::toInt)
    val s = TreeSet<Int>()
    val a = mutableListOf(b[0])
    s.add(b[0])
    var cur = b[0]
    val inf = 1e9.toInt()
    for (x in b.drop(1)) {
        if (x == cur) {
            a.add(inf)
            a.add(-inf)
        } else if (x < cur) {
            val prev = s.lower(cur)?:(-inf - 1)
            if (prev >= -inf && prev > x) {
                println("No")
                return
            } else if (prev == x) {
                a.add(-inf)
                a.add(-inf)
            } else {
                a.add(x)
                a.add(-inf)
                s.add(x)
            }
            cur = x
        } else {
            val next = s.higher(cur)?:(inf + 1)
            if (next <= inf && next < x) {
                println("No")
                return
            } else if (next == x) {
                a.add(inf)
                a.add(inf)
            } else {
                a.add(x)
                a.add(inf)
                s.add(x)
            }
            cur = x
        }
    }
    println("Yes")
//    println(a.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}