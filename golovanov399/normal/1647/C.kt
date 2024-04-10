import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!! }
    if (a[0][0] == '1') {
        println(-1)
        return
    }
    println(n * m)
    for (i in n - 1 downTo 1) {
        for (j in 0 until m) {
            println("${if (a[i][j] == '0') (i + 1) else i} ${j + 1} ${i + 1} ${j + 1}")
        }
    }
    for (j in m - 1 downTo 1) {
        println("1 ${if (a[0][j] == '0') (j + 1) else j} 1 ${j + 1}")
    }
    println("1 1 1 1")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}