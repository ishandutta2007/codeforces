import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun getDigits(_x: Long): MutableList<Int> {
    var ans = mutableListOf<Int>()
    var x = _x
    while (x > 0) {
        ans.add((x % 10).toInt())
        x /= 10
    }
    return ans
}

fun solve() {
    var (a, k) = readLine()!!.split(' ').map(String::toLong)
    while (k > 1) {
        k -= 1
        if (getDigits(a).min() == 0) {
            break
        }
        a += getDigits(a).min()!! * getDigits(a).max()!!
    }
    println(a)
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}