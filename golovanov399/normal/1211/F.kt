import kotlin.math.min
import kotlin.system.exitProcess

fun findInStr(s: String, c: Char): Int {
    for (i in s.indices) {
        if (s[i] == c) {
            return i
        }
    }
    return -1
}

fun main() {
    var n = readLine()!!.toInt()
    var a = MutableList<MutableList<Pair<Int, Int>>>(6) { mutableListOf() }
    val ks: String = "kotlin"
    for (i in 0 until n) {
        val s = readLine()!!
        val l = findInStr(ks, s[0])
        val r = (findInStr(ks, s.last()) + 1) % 6
        a[l].add(Pair(i, r))
    }

    var ptr = Array(6) {0}
    var usedEdge = Array(n) {false}
    var ans = mutableListOf<Int>()
    fun eulerCycle(u: Int) {
        while (ptr[u] < a[u].size && usedEdge[a[u][ptr[u]].first]) {
            ptr[u] += 1
        }
        if (ptr[u] == a[u].size) {
            return
        }
        val id = a[u][ptr[u]].first
        val to = a[u][ptr[u]].second
        usedEdge[id] = true
        eulerCycle(to)
        ans.add(id + 1)
        eulerCycle(u)
    }
    eulerCycle(0)

    println(ans.reversed().joinToString(" "))
}