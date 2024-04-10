import kotlin.math.*

data class Contest(val days: Int, val gap: Int)

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map {
        val (k, t) = readLine()!!.split(' ').map(String::toInt)
        Contest(k, t)
    }
    if (a.sumOf { it.days } > m) {
        println("-1")
        return
    }
    val totalDouble = a.filter { it.gap == 2 }.sumOf { it.days }
    val prs = a.fold(List(totalDouble + 1) { if (it == 0) 0 else -1 }) { old, c ->
        if (c.gap == 1) {
            old
        } else {
            List(totalDouble + 1) { i ->
                if (old[i] > -1) {
                    old[i]
                } else if (i >= c.days && old[i - c.days] > -1) {
                    i - c.days
                } else {
                    -1
                }
            }
        }
    }

    val minDouble = prs.withIndex().first { it.index * 2 >= totalDouble && it.value > -1 }.index
    var from = minDouble * 2 - 1 + (if (minDouble * 2 == totalDouble) 1 else 0)
    if (from + a.filter { it.gap == 1 }.sumOf { it.days } > m) {
        println("-1")
        return
    }

    var cur = minDouble
    var cur0 = 0
    var cur1 = 1
    val ans = a.reversed().map { c ->
        when {
            c.gap == 1 -> {
                from.also { from += c.days }
            }
            cur - prs[cur] != c.days -> {
                cur1.also { cur1 += 2 * c.days }
            }
            else -> {
                cur = prs[cur]
                cur0.also { cur0 += 2 * c.days }
            }
        }
    }
    println(ans.reversed().map(Int::inc).joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}