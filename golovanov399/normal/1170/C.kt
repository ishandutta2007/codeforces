fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}

fun solve() {
    val s = readLine()!!
    val t = readLine()!!
    var l = 0
    var r = 0
    while (r < t.length) {
        if (l >= s.length) {
            println("NO")
            return
        } else if (s[l] == t[r]) {
            l += 1
            r += 1
        } else if (s[l] == '+' && t[r] == '-') {
            println("NO")
            return
        } else if (l + 1 >= s.length || s[l + 1] != '-') {
            println("NO")
            return
        } else {
            l += 2
            r += 1
        }
    }
    println(if (l == s.length) "YES" else "NO")
}