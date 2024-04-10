import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val s = readLine()!!
    var rem = s.count { it == '1' }
    var cur = 0
    var indices = MutableList(n) { it }
    while (rem > 0) {
        if (s[cur] == '1') {
            rem -= 1
        }
        var idx = indices.binarySearch(cur)
        indices.remove(cur)
        if (indices.isEmpty()) {
            break
        }
        idx = (idx + k - 1) % indices.size
        cur = indices.getOrNull(idx) ?: -1
    }
    println(n - indices.size)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}