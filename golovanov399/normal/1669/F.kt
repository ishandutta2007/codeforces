import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var (l, r) = 0 to n - 1
    var ans = 0
    var bal = 0
    while (l <= r) {
        if (bal <= 0) {
            bal += a[l]
            l += 1
        } else {
            bal -= a[r]
            r -= 1
        }
        if (bal == 0) {
            ans = l + n - 1 - r
        }
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}