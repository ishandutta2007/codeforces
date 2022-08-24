import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var idx = 0
    for (i in 1 until a.size) {
        if (a[i] != 0 && (abs(a[i]) < abs(a[idx]) || a[idx] == 0)) {
            idx = i
        }
    }
    var answer: Int = a.filter { it > 0 }.sum() - abs(a[idx])
    var ans = CharArray(a.size) {'0'}
    for (i in a.indices) {
        if ((a[i] > 0 && i != idx) || (a[i] < 0 && i == idx)) {
            ans[i] = '1'
        }
    }
    println(answer)
    println(ans.joinToString(separator = ""))
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}