fun solve() {
    val s = readLine()!!
    if ('1' !in s) {
        println(0)
        return
    }
    val l = s.indexOfFirst { it == '1' }
    val r = s.indexOfLast { it == '1' }
    println(s.substring(l, r).count { it == '0' })
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}