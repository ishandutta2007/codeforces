import kotlin.math.*

fun main(args: Array<String>) {
    var t = readLine()!!.toInt()
    repeat(t) {
        var (n, x, y) = readLine()!!.split(" ").map{ it.toInt() }
        if (x > y) {
            var tmp = x
            x = y
            y = tmp
        }
        --x
        --y
        var ans = Int.MAX_VALUE
        for (i in 1 until n) {
            var time = 0
            if (x < i) {
                time = min(x, i - 1 - x) + i - 1
            } else {
                time = x
            }
            if (y < i) {
                time = max(time, n - y - 1)
            } else {
                time = max(time, min(y - i, n - 1 - y) + n - i - 1)
            }
            if (time < ans) ans = time
        }
        println(ans)
    }
}