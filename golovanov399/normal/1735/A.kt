fun solve() {
    val n = readLine()!!.toInt() - 3
    println((n - 3) / 3)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}