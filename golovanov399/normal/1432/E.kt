import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    var (n, k) = readLine()!!.split(' ').map(String::toLong)
    val s = readLine()!!
    var t = mutableListOf<Char>()
    for (i in 0 until n.toInt()) {
        if (s[i] == '0') {
            val tmp = min(k, i.toLong() - t.size).toInt()
            val pos = i - tmp
            repeat(pos - t.size) {
                t.add('1')
            }
            t.add('0')
            k -= tmp
        }
    }
    repeat(n.toInt() - t.size) {
        t.add('1')
    }
    println(t.joinToString(""))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}