import kotlin.math.*

data class Op(val x: Int, val y: Int, val z: Int)

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong)
    if (a[n - 2] > a[n - 1]) {
        println(-1)
        return
    }
    run {
        var sorted = true
        for (i in 0 until n - 1) {
            if (a[i] > a[i + 1]) {
                sorted = false
            }
        }
        if (sorted) {
            println(0)
            return
        }
    }
    if (a[n - 1] < 0) {
        println(-1)
        return
    }
    val ans = mutableListOf<Op>()
    for (i in n - 3 downTo 0) {
        ans.add(Op(i, i + 1, n - 1))
    }
    println(ans.size)
    for ((x, y, z) in ans) {
        println("${x + 1} ${y + 1} ${z + 1}")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}