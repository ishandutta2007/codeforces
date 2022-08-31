import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var answer = 0
    for (bobs in -30..30) {
        var cur = 0
        var curmin = 0
        var cnt = 0
        for (x in a) {
            if (x > bobs) {
                cur = 0
                curmin = 0
                cnt = 0
            } else {
                cur += x
                answer = max(answer, cur - curmin - bobs)
                curmin = min(curmin, cur)
                cnt += 1
            }
        }
    }
    println(answer)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}