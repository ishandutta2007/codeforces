import kotlin.math.*

data class Attack(val guy: Int, val bar: Int, val dmg: Long)

class SegTree(private val _n: Int, private val f: (Long, Long) -> Long) {
    private val n = (_n - 1).takeHighestOneBit() * 2
    private val a = MutableList(n * 2) { 0L }

    fun initialize(ar: List<Long>) {
        for (i in ar.indices) {
            a[n + i] = ar[i]
        }
        for (i in n - 1 downTo 0) {
            a[i] = f(a[i + i], a[i + i + 1])
        }
    }

    private fun get(v: Int, l: Int, r: Int, ql: Int, qr: Int): Long {
        if (ql <= l && qr >= r) {
            return a[v]
        }
        val m = (l + r) / 2
        return when {
            ql >= m -> {
                get(v + v + 1, m, r, ql, qr)
            }
            qr <= m -> {
                get(v + v, l, m, ql, qr)
            }
            else -> {
                f(get(v + v, l, m, ql, qr), get(v + v + 1, m, r, ql, qr))
            }
        }
    }

    fun get(l: Int, r: Int): Long = get(1, 0, n, l, r)

    fun upd(pos: Int, x: Long) {
        var i = pos + n
        a[i] = x
        while (i > 1) {
            i /= 2
            a[i] = f(a[i + i], a[i + i + 1])
        }
    }
}


fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val attacks = mutableListOf(Attack(-1, m, 0L))
    for (i in 0 until n) {
        readLine()
        val dmgs = readLine()!!.split(' ').map(String::toInt)
        val bars = readLine()!!.split(' ').map(String::toInt)
        dmgs.zip(bars).forEach { (d, b) -> attacks.add(Attack(i, b, d.toLong())) }
    }
    attacks.sortWith(compareBy({ it.guy + it.bar }, { it.bar }))

    val tree = SegTree(m + 1) { x, y -> max(x, y) }
    tree.initialize(List(m + 1) { Long.MIN_VALUE / 2 })
    var ans = 0L
    for ((i, j, d) in attacks) {
        if (i == -1) {
            tree.upd(m, 0L)
            continue
        }
        val dmg = tree.get(j, m + 1) + d
        ans = max(ans, dmg)
        tree.upd(j, dmg)
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}