fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    println((n * m + 1) / 2)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}