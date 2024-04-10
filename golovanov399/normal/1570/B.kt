import kotlin.math.*

fun solve() {
    val a = (0..1).map { readLine()!!.toInt() }
    val k = (0..1).map { readLine()!!.toInt() }
    val n = readLine()!!.toInt()
    println("${max(
            0, 
            n - a[0] * (k[0] - 1) - a[1] * (k[1] - 1))
    } ${
        (0..1).map { t ->
            min(n / k[t], a[t]) + max(0, n - a[t] * k[t]) / k[1 - t]
        }.maxOrNull()!!
    }")
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}