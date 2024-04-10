import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong).toMutableList()
    val cnt = (1 until n - 1).count { i -> a[i] > a[i - 1] && a[i] > a[i + 1] }
    var i = 1
    var ans = cnt
    while (i < n - 3) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1] && a[i + 2] > a[i + 1] && a[i + 2] > a[i + 3]) {
            ans -= 1
            a[i + 1] = max(a[i], a[i + 2])
            i += 2
        }
        i += 1
    }
    for (i in 1 until n - 1) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            a[i] = max(a[i - 1], a[i + 1])
        }
    }
    println(ans)
    println(a.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}