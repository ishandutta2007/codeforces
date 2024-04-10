import kotlin.math.*

fun half(x: Int) = if (x % 2 == 0 || x >= 0) x / 2 else (x / 2 - 1)

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!! }
    val blacks = arrayOfNulls<Pair<Int, Int>>(4)
    val dirs = listOf(1 to 1, 1 to -1, -1 to 1, -1 to -1)
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (a[i][j] == 'B') {
                for (k in 0 until 4) {
                    if (blacks[k] == null || (blacks[k]!!.first - i) * dirs[k].first + (blacks[k]!!.second - j) * dirs[k].second > 0) {
                        blacks[k] = i to j
                    }
                }
            }
        }
    }
    var s = half(blacks[0]!!.first + blacks[3]!!.first + blacks[0]!!.second + blacks[3]!!.second)
    var d = half(blacks[1]!!.first + blacks[2]!!.first - blacks[1]!!.second - blacks[2]!!.second)
    if (s % 2 != abs(d) % 2) {
        if (abs(blacks[0]!!.first - blacks[3]!!.first + blacks[0]!!.second - blacks[3]!!.second) < abs(blacks[1]!!.first - blacks[2]!!.first - blacks[1]!!.second + blacks[2]!!.second)) {
            s += 1
        } else {
            d += 1
        }
    }
    println("${(s + d) / 2 + 1} ${(s - d) / 2 + 1}")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}