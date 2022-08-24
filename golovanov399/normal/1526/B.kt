import kotlin.math.*

fun solve() {
    val x = readLine()!!.toInt()
    if (x >= 11 * 111) {
        println("YES")
    } else {
        for (i in 0..(x / 111)) {
            if ((x - i * 111) % 11 == 0) {
                println("YES")
                return
            }
        }
        println("NO")
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}