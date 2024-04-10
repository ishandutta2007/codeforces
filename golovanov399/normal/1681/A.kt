fun solve() {
    readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    readLine()!!.toInt()
    val b = readLine()!!.split(" ").map(String::toInt)
    println(if (a.maxOrNull()!! >= b.maxOrNull()!!) "Alice" else "Bob")
    println(if (a.maxOrNull()!! > b.maxOrNull()!!) "Alice" else "Bob")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}