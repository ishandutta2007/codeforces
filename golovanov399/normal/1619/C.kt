import kotlin.math.*

fun solve() {
    val (a, s) = readLine()!!.split(' ').map(String::reversed)
    val b = mutableListOf<Int>()
    var i = 0
    var ok = true
    for (c in a) {
        if (i == s.length) {
            ok = false
            break
        } else if (s[i] >= c) {
            b.add(s[i] - c)
            i += 1
        } else if (i + 1 == s.length || s[i + 1] != '1') {
            ok = false
            break
        } else {
            b.add(s[i] - c + 10)
            i += 2
        }
    }
    while (i < s.length) {
        b.add(s[i] - '0')
        i += 1
    }
    if (!ok) {
        b.clear()
        b.add(-1)
    }
    while (b.last() == 0) {
        b.removeLast()
    }
    println(b.reversed().joinToString(""))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}