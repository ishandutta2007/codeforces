import java.util.*
import kotlin.math.*

fun solve() {
    val q = readLine()!!.toInt()
    var m = IntArray(222_222) { 0 }
    var l = 0
    var r = 1
    repeat (q) {
        val (c, id_s) = readLine()!!.split(' ')
        val id = id_s.toInt()
        if (c == "L") {
            m[id] = l
            l -= 1
        } else if (c == "R") {
            m[id] = r
            r += 1
        } else {
            println(min(m[id]!! - l, r - m[id]!!) - 1)
        }
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}