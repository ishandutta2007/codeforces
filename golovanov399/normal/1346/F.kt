import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m, q) = readLine()!!.split(' ').map(String::toInt)
    var a = MutableList(n) { readLine()!!.split(' ').map(String::toInt).toMutableList() }
    var xs = LongArray(n) { 0L }
    var ys = LongArray(m) { 0L }
    for (i in 0 until n) {
        for (j in 0 until m) {
            xs[i] = xs[i] + a[i][j]
            ys[j] = ys[j] + a[i][j]
        }
    }

    fun getMinCnt(a: LongArray): Long {
        val sum = a.sum()
        var cur = 0L
        var mid = 0
        while (2 * (cur + a[mid]) < sum) {
            cur += a[mid]
            mid += 1
        }
        var ans = 0L
        for (i in a.indices) {
            ans += a[i] * abs(mid - i)
        }
        return ans
    }

    var answer = mutableListOf<Long>(getMinCnt(xs) + getMinCnt(ys))
    repeat (q) {
        val (x, y, z) = readLine()!!.split(' ').mapIndexed { i, t -> if (i == 2) t.toInt() else t.toInt() - 1 }
        xs[x] = xs[x] + z - a[x][y]
        ys[y] = ys[y] + z - a[x][y]
        a[x][y] = z
        answer.add(getMinCnt(xs) + getMinCnt(ys))
    }
    println(answer.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}