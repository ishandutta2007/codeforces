import kotlin.math.min
import kotlin.system.exitProcess

fun solve() {
    val n = readLine()!!.toInt()
    var c = readLine()!!.split(' ').map(String::toInt).toMutableList()
    val d = readLine()!!.split(' ').map(String::toInt).toMutableList()
    var a = Array(n) { mutableListOf<Int>() }
    for (i in 1 until n) {
        var (u, v) = readLine()!!.split(' ').map(String::toInt)
        u -= 1
        v -= 1
        a[u].add(v)
        a[v].add(u)
    }

    if (c == d) {
        println("Yes\n0")
        return
    }

    if (c.sorted() != d.sorted()) {
        println("No")
        return
    }

    var deg = IntArray(n) {a[it].size}
    var thrown = BooleanArray(n) {false}
    var single = mutableListOf<Int>()
    for (i in 0 until n) {
        if (a[i].size == 1) {
            single.add(i)
        }
    }
    var idx = 0
    while (idx < single.size) {
        val v = single[idx]
        idx += 1
//        single.removeAt(single.size - 1)
        if (c[v] != d[v]) {
            continue
        }
        thrown[v] = true
        for (x in a[v]) {
            if (thrown[x]) {
                continue
            }
            deg[x] -= 1
            if (deg[x] == 1) {
                single.add(x)
            }
        }
    }

    var ok = true
    for (i in 0 until n) {
        if (!thrown[i] && deg[i] > 2) {
            ok = false
        }
    }

    if (!ok) {
        println("No")
        return
    }

    var way = mutableListOf<Int>()
    var v = 0
    while (thrown[v] || deg[v] > 1) {
        v += 1
    }
    while (true) {
        way.add(v)
        thrown[v] = true
        var nx = -1
        for (x in a[v]) {
            if (!thrown[x]) {
                nx = x
            }
        }
        if (nx == -1) {
            break
        }
        v = nx
    }

    val backup = c.toIntArray()
    for (i in 0 until way.size - 1) {
        c[way[i]] = c[way[i + 1]].also { c[way[i + 1]] = c[way[i]] }
    }
    if (c == d) {
        println("Yes")
        println(way.size)
        for (i in 0 until way.size) {
            way[i] += 1
        }
        println(way.joinToString(" "))
        return
    }
    c = backup.toMutableList()
    way.reverse()
    for (i in 0 until way.size - 1) {
        c[way[i]] = c[way[i + 1]].also { c[way[i + 1]] = c[way[i]] }
    }
    if (c == d) {
        println("Yes")
        println(way.size)
        for (i in 0 until way.size) {
            way[i] += 1
        }
        println(way.joinToString(" "))
        return
    }
    println("No")
}

fun main() {
    val t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}