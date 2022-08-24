import kotlin.math.*

fun solve() {
    val s = readLine()!!
    var mask = 0
    for (c in s) {
        if (c == 'r') {
            mask = mask or 1
        } else if (c == 'g') {
            mask = mask or 2
        } else if (c == 'b') {
            mask = mask or 4
        } else if (c == 'R') {
            if (mask and 1 == 0) {
                println("NO")
                return
            }
        } else if (c == 'G') {
            if (mask and 2 == 0) {
                println("NO")
                return
            }
        } else if (c == 'B') {
            if (mask and 4 == 0) {
                println("NO")
                return
            }
        }
    }
    println("YES")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}