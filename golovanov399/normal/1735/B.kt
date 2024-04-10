fun solve() {
    readLine()!!
    val a = readLine()!!.split(' ').map(String::toInt)
    println(a.sumOf { x -> (x - 1) / (2 * a[0] - 1) })
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}