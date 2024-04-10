import kotlin.math.*

const val inf = Int.MAX_VALUE / 10

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    val guys = a.withIndex().filter { it.value == 1 }.map { it.index }
    val sz = guys.size
    val res = a.asSequence().withIndex().filter { it.value == 0 }.map { it.index }.fold(
            List(sz + 1) { if (it > 0) inf else 0 }
    ) { dp, pos ->
        dp.indices.map { k ->
            if (k == 0) 0 else {
                min(dp[k], dp[k - 1] + abs(guys[k - 1] - pos))
            }
        }
    }.last()
    println(res)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}