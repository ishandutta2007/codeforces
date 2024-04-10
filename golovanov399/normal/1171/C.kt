fun solve() {
    val s = readLine()!!
    var a = s.toMutableList()
    a.sort()
    if (a.first() == a.last()) {
        println(-1)
    } else {
        println(a.joinToString(prefix = "", postfix = "", separator = ""))
    }
}

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}