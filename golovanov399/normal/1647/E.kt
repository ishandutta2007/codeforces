import java.util.*
import kotlin.math.*

const val L = 30

fun solve() {
    val n = readLine()!!.toInt()
    val p = readLine()!!.split(' ').map { it.toInt() - 1 }
    val a = readLine()!!.split(' ').map { it.toInt() - 1 }

    val empties = BooleanArray(n) { true }
    p.forEach { empties[it] = false }
    val cnt = empties.count { it }
    val its = (a.maxOrNull()!! - n + 1) / cnt

    val pp = (0..L).scan(p) { pr, _ ->
        (0 until n).map { pr[pr[it]] }
    }

    fun jump(v: Int, k: Int): Int {
        var u = v
        for (i in 0..L) {
            if (k and (1 shl i) > 0) {
                u = pp[i][u]
            }
        }
        return u
    }

    val used = BooleanArray(n) { false }
    val reserved = BooleanArray(n) { false }
    a.filter { it < n }.forEach { reserved[it] = true }
    val remaining = TreeSet<Int>()
    (0 until n).filter { !reserved[it] }.forEach { remaining.add(it) }
    val ans = IntArray(n) { -1 }
    for (i in 0 until n) {
        val j = jump(i, its)
        val x = a[j]
        if (!used[x]) {
            used[x] = true
            ans[i] = x
        } else {
            val y = remaining.higher(x)!!
            ans[i] = y
            remaining.remove(y)
        }
    }
    println(ans.map(Int::inc).joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}