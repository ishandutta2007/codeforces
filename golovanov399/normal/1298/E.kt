import kotlin.math.*
import kotlin.system.exitProcess

fun main() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val r = readLine()!!.split(' ').map(String::toInt).toIntArray()
    var a = Array(n) { mutableListOf<Int>() }
    for (i in 0 until m) {
        val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
        a[u].add(v)
        a[v].add(u)
    }
    var ans = IntArray(n)
    val order = IntArray(n) { it }.sortedWith(compareBy {r[it]})
    var pr_idx = 0
    var used = BooleanArray(n) { false }
    for (i in 0 until n) {
        while (r[order[pr_idx]] < r[order[i]]) {
            used[order[pr_idx]] = true
            ++pr_idx
        }
        ans[order[i]] = pr_idx
        for (x in a[order[i]]) {
            if (used[x]) {
                ans[order[i]] -= 1
            }
        }
    }

    println(ans.joinToString(separator = " "))
}