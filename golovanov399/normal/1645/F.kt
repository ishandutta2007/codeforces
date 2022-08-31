import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val mx = a.maxOrNull()!! + 1
    val cnt = MutableList(mx + 1) { 0 }
    a.forEach { cnt[it - 1] += 1 }
    val dp = cnt.fold(listOf(Int.MIN_VALUE / 2, 0, Int.MIN_VALUE / 2)) { pr, c ->
        listOf(
                maxOf(pr[0], pr[1], if (c > 0) pr[0] + 1 else Int.MIN_VALUE),
                if (c > 1) maxOf(pr[2] + 1, pr[1] + 1, pr[0] + 2) else if (c == 1) maxOf(pr[0], pr[1], pr[2]) + 1 else pr[2] + 1,
                if (c > 2) maxOf(pr[0] + 2, pr[1] + 1, pr[2] + 1) else if (c > 1) max(pr[1] + 1, pr[2] + 1) else if (c > 0) pr[2] + 1 else Int.MIN_VALUE / 2
        )
    }
    println(dp.maxOrNull())
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}