fun solve() {
    val x = readLine()!!.toInt()
    println(x / 2)
}

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}