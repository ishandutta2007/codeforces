import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k, x, y) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toLong).sorted().reversed()
    var ans_without_rearranging = 0L
    var ans_with_rearranging = y.toLong()
    var total = a.sum()
    for (cnt in a) {
        if (cnt <= k) {
            break
        }
        ans_without_rearranging += x
    }
    for (cnt in a) {
        if (total <= k.toLong() * n) {
            break
        }
        total -= cnt
        ans_with_rearranging += x
    }
    println(min(ans_with_rearranging, ans_without_rearranging))
}

fun main() {
    val t = readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}