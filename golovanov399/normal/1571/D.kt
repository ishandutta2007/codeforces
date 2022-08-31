import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val cntBoth = MutableList(n) { MutableList(n) { 0 } }
    val cntFirst = MutableList(n) { 0 }
    val cntLast = MutableList(n) { 0 }
    var our = -1 to -1
    repeat (m) {
        val (f, l) = readLine()!!.split(' ').map(String::toInt).map(Int::dec)
        cntFirst[f] += 1
        cntLast[l] += 1
        cntBoth[f][l] += 1
        if (our.first == -1) {
            our = f to l
        }
    }
    var ans = 0
    for (f in 0 until n) {
        for (l in 0 until n) {
            if (f == l) {
                continue
            }
            val c2 = cntBoth[f][l]
            val c1 = cntFirst[f] + cntLast[l] - 2 * cntBoth[f][l]
            val us = (if (our.first == f) 1 else 0) + (if (our.second == l) 1 else 0)
            val place = 1 + (if (us < 2) c2 else 0) + (if (us < 1) c1 else 0)
            ans = max(ans, place)
        }
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}