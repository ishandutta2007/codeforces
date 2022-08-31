import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val guys = IntArray(n) { it }.sortedBy { a[it] }
    var ans = IntArray(n) { 0 }
    var cur = 0
    var i = 0
    while (cur + a[guys[i]] < n) {
        cur += a[guys[i]]
        ans[cur] = guys[i] + 1
        i += 1
    }
    cur = 0
    while (i < n) {
        while (ans[cur] > 0) {
            cur += 1
        }
        ans[cur] = guys[i] + 1
        i += 1
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}