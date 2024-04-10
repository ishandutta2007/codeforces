import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    var S = TreeSet<Pair<Int, Int>>(kotlin.Comparator { o1, o2 -> if (o1.first == o2.first) o1.second - o2.second else o2.first - o1.first })
    S.add(Pair(n, 0))
    var ans = IntArray(n) {0}
    for (i in 1..n) {
        val seg = S.first()!!
        S.remove(seg)
        ans[seg.second + (seg.first - 1) / 2] = i
        if (seg.first >= 3) {
            S.add(Pair((seg.first - 1) / 2, seg.second))
        }
        if (seg.first >= 2) {
            S.add(Pair(seg.first / 2, seg.second + (seg.first - 1) / 2 + 1))
        }
    }
    println(ans.joinToString(separator = " "))
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}