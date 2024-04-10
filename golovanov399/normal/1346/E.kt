import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    var a = IntArray(n) { -1 }
    a[k - 1] = 0
    repeat (m) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
        if (a[x] == -1 && a[y] == -1) {
            //
        } else if (a[x] == -1) {
            a[x] = a[y]
            a[y] += 1
        } else if (a[y] == -1) {
            a[y] = a[x]
            a[x] += 1
        } else {
            val for_x = min(a[x] + 1, a[y])
            val for_y = min(a[y] + 1, a[x])
            a[x] = for_x
            a[y] = for_y
        }
    }
    println(a.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}