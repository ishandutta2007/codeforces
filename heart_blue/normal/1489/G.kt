import java.util.*
import kotlin.Comparator

class UnionFind {
    var p = Array<Int>(1, { it -> 0 })
    fun init(n: Int) {
        p = Array<Int>(n, { it -> -1 })
    }

    fun treesize(x: Int): Int {
        return -p[Find(x)];
    }

    fun Find(y: Int): Int {
        var x = y
        var s = x
        while (p[s] >= 0) s = p[s];
        while (x != s) {
            var t = p[x];
            p[x] = s;
            x = t;
        }
        return s;
    }

    fun Union(kx: Int, ky: Int) {
        var x = kx
        var y = ky
        var px = Find(x);
        var py = Find(y);
        if (p[px] > p[py]) px = py.apply { py = px }
        p[px] += p[py];
        p[py] = px;
    }
};
fun main() {
    var key = readLine()!!.split(" ").map(String::toInt)
    var n = key[0]
    var m = key[1]
    var a = readLine()!!.split(" ").map(String::toLong).toLongArray()
    var vp = mutableListOf<Triple<Long, Int, Int>>()
    var k = 0
    for (i in 0 until n) {
        if (a[i] < a[k])
            k = i
    }
    for (i in 0 until n) {
        vp.add(Triple<Long, Int, Int>(a[k] + a[i], k + 1, i + 1))
    }
    for (i in 1..m) {
        var s = readLine()!!.split(" ").map(String::toLong)
        var u = s[0].toInt()
        var v = s[1].toInt()
        var w = s[2]
        vp.add(Triple<Long, Int, Int>(w, u, v))
    }
    vp.sortWith(compareBy({ it.first }))
    var uf = UnionFind()
    uf.init(n + 1)
    var ans: Long = 0
    for (p in vp) {
        //println(p)
        var w = p.first
        var u = p.second
        var v = p.third
        if (uf.Find(u) != uf.Find(v)) {
            ans += w
            uf.Union(u, v)
        }
    }
    println("${ans}")
}