fun solve() {
    val (x1, y1, x2, y2) = readLine()!!.split(' ').map(String::toLong)
    println((x2 - x1) * (y2 - y1) + 1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}