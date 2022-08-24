fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted().reversed()
    for (i in 0 until n) {
        if (a[i] <= n - i) {
            println(n - i + 1)
            return
        }
    }
    println(1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}