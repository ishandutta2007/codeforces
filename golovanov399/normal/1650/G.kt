import kotlin.math.*

const val mod = 1_000_000_007

fun solve() {
    readLine()
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val (s, t) = readLine()!!.split(' ').map(String::toInt).map(Int::dec)
    val a = List(n) { mutableListOf<Int>() }
    repeat (m) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
        a[x].add(y)
        a[y].add(x)
    }
    var layer = listOf(s)
    val d = IntArray(n) { if (it == s) 0 else 1e9.toInt() }
    val cnt0 = IntArray(n) { if (it == s) 1 else 0 }
    val cnt1 = IntArray(n) { 0 }
    while (layer.isNotEmpty()) {
        for (v in layer) {
            for (x in a[v]) {
                if (d[x] == d[v]) {
                    cnt1[x] += cnt0[v]
                    if (cnt1[x] >= mod) {
                        cnt1[x] -= mod
                    }
                }
            }
        }
        val newLayer = mutableListOf<Int>()
        for (v in layer) {
            for (x in a[v]) {
                if (d[x] > d[v] + 1) {
                    d[x] = d[v] + 1
                    newLayer.add(x)
                }
                if (d[x] == d[v] + 1) {
                    cnt0[x] += cnt0[v]
                    if (cnt0[x] >= mod) {
                        cnt0[x] -= mod
                    }
                    cnt1[x] += cnt1[v]
                    if (cnt1[x] >= mod) {
                        cnt1[x] -= mod
                    }
                }
            }
        }
        layer = newLayer
    }
    println((cnt0[t] + cnt1[t]) % mod)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}