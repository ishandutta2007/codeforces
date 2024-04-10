import kotlin.math.*
import kotlin.system.exitProcess

class Fenwick(val n: Int) {
    var a: IntArray = IntArray(n) { 0 }

    fun add(p: Int, x: Int) {
        var pos = p
        while (pos < n) {
            a[pos] += x
            pos = pos or (pos + 1)
        }
    }

    fun get(p: Int): Long {
        var pos = p
        var res: Long = 0
        while (pos >= 0) {
            res += a[pos]
            pos = (pos and (pos + 1)) - 1
        }
        return res
    }
}

fun lowerBound(a: List<Int>, x: Int): Int {
    var l = -1
    var r = a.size
    while (r > l + 1) {
        val m = (l + r) / 2
        if (a[m] >= x) {
            r = m
        } else {
            l = m
        }
    }
    return r
}

fun main() {
    var (n, m) = readLine()!!.split(' ').map(String::toInt)
    var a = readLine()!!.split(' ').map(String::toInt).toList()
    val all_guys = a.sorted().distinct()
    a = a.map { x -> lowerBound(all_guys, x) }
    if (!all_guys.contains(m)) {
        println(0)
        exitProcess(0)
    }
    m = lowerBound(all_guys, m)

    var ans = -n.toLong() * (n + 1) / 2
    for (t in 0..1) {
        var balance = 0
        var f = Fenwick(2 * n + 1)
        f.add(balance + n, 1)
        for (x in a) {
            balance += if (x >= m) 1 else -1
            ans += f.get(balance - 1 + t + n)
            f.add(balance + n, 1)
        }

        a = a.map { x -> -x }
        m = -m
    }
    
    println(ans)
}