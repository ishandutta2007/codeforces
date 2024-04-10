fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    readLine()!!.toInt()
    println(a[(readLine()!!.split(" ").map(String::toLong).sum() % n).toInt()])
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}