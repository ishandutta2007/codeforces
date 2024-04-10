import kotlin.math.max

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}

fun solve() {
    val n = readLine()!!.toInt()
    var a = Array(n) {
        val spl = readLine()!!.split(' ').map(String::toInt)
        Triple(spl[0], spl[1], it)
    }
    a.sortWith(compareBy({it.first}, {it.second}, {it.third}))

    var r = a[0].second
    var ans = Array(n, {2})
    for (i in 0 until n) {
        if (a[i].first > r) {
            println(ans.joinToString(separator = " "))
            return
        }
        ans[a[i].third] = 1
        r = max(r, a[i].second)
    }
    println(-1)
}