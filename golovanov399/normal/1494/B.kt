import kotlin.math.*

fun solve() {
    val line = readLine()!!.split(' ').map(String::toInt)
    val n = line[0]
    val a = line.drop(1)
    for (mask in 0 until 16) {
        var b = (0..3).map { i -> (mask shr i) % 2 }
        var ok = true
        for (i in 0 until 4) {
            if (b[i] + b[(i + 1) % 4] - a[i] !in (2 - n..0)) {
                ok = false
            }
        }
        if (ok) {
            println("Yes")
            return
        }
    }
    println("No")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}