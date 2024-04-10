import kotlin.math.*

const val mod = 998_244_353

fun solve() {
    val (n, m, k, q) = readLine()!!.split(' ').map(String::toInt)
    val qrs = (0 until q).map {
        readLine()!!.split(' ').map { it.toInt() - 1 }
    }.reversed()
    var cnt = 0
    val row = mutableSetOf<Int>()
    val col = mutableSetOf<Int>()
    for ((x, y) in qrs) {
        if (!row.contains(x) || !col.contains(y)) {
            cnt += 1
        }
        row.add(x)
        col.add(y)
        if (row.size == n || col.size == m) {
            break
        }
    }
    var ans = 1L
    repeat(cnt) {
        ans = ans * k % mod
    }
    println(ans)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}