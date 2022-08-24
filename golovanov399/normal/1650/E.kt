import kotlin.math.*

fun solve() {
    readLine()
    val (n, d) = readLine()!!.split(' ').map(String::toInt)
    val a = listOf(0) + readLine()!!.split(' ').map(String::toInt)
    fun can(len: Int): Boolean {
        val bad = a.zipWithNext().filter { (x, y) -> y - x < len }
        if (bad.isEmpty()) {
            return true
        }
        val gays = bad.asSequence().map { (x, y) -> setOf(x, y) }.reduce(Set<Int>::intersect).filter { it != 0 }
        for (g in gays) {
            val tmp = (a.filter { it != g } + listOf(d + len)).zipWithNext().map { (x, y) -> y - x }
            if (tmp.any { it >= 2 * len } && tmp.all { it >= len }) {
                return true
            }
        }
        return false
    }
    var (l, r) = 1 to d / n + 1
    while (r > l + 1) {
        val m = (l + r) / 2
        if (can(m)) {
            l = m
        } else {
            r = m
        }
    }
    println(l - 1)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}