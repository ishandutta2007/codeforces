import java.util.*
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val sm = mutableMapOf<Int, Long>()
    for (i in 0 until n) {
        sm[a[i]] = (sm[a[i]]?:0L) + n - i
    }
    var ans = 0L
    for (i in 0 until n) {
        sm[a[i]] = sm[a[i]]!! - (n - i)
        ans += (i + 1) * sm[a[i]]!!
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}