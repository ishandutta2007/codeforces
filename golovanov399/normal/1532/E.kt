import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    readLine()
    val a = readLine()!!.split(' ').map(String::toLong)
    val s = a.sum()
    val m = mutableMapOf<Long, Int>()
    a.forEach { x -> m[x] = m.getOrDefault(x, 0) + 1 }
    val ans = a.withIndex().filter { (_, v) ->
        val rem = (s - v) / 2
        rem * 2 + v == s && (m.getOrDefault(rem, 0) - if (v == rem) 1 else 0) > 0
    }.map { it.index + 1 }
    println(ans.size)
    println(ans.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}