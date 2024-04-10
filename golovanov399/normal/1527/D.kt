class Dsu(n: Int) {
    var p = IntArray(n) { it }
    var rk = IntArray(n) { 0 }
    var sz = IntArray(n) { 1 }

    fun get(v: Int): Int {
        return if (v == p[v]) {
            v
        } else {
            p[v] = get(p[v])
            p[v]
        }
    }

    fun merge(_u: Int, _v: Int) {
        var u = get(_u)
        var v = get(_v)
        if (u == v) {
            return
        }
        if (rk[u] < rk[v]) {
            val w = v
            v = u
            u = w
        }
        p[v] = u
        sz[u] += sz[v]
        if (rk[u] == rk[v]) {
            rk[u] += 1
        }
    }

    fun getSize(v: Int): Int = sz[get(v)]
}

fun c2(x: Int): Long = 1L * x * (x - 1) / 2

fun solve() {
    val n = readLine()!!.toInt()
    val a = MutableList(n) { mutableListOf<Int>() }
    repeat (n - 1) {
        val (u, v) = readLine()!!.split(' ').map(String::toInt)
        a[u].add(v)
        a[v].add(u)
    }

    val tin = IntArray(n) { 0 }
    val tout = IntArray(n) { 0 }
    val sz = IntArray(n) { 0 }
    val par = IntArray(n) { 0 }
    var timer = 0
    fun dfs(v: Int, p: Int) {
        par[v] = p
        tin[v] = timer
        timer += 1
        sz[v] = 1
        for (x in a[v]) {
            if (x != p) {
                dfs(x, v)
                sz[v] += sz[x]
            }
        }
        tout[v] = timer
    }
    dfs(0, -1)

    fun isPar(u: Int, v: Int): Boolean = tin[u] <= tin[v] && tout[u] >= tout[v]

    val res = LongArray(n + 1) { 0L }
    res[0] = c2(n)
    var (u, v) = listOf(0, 0)
    res[1] = res[0]
    for (x in a[0]) {
        if (isPar(0, x)) {
            res[1] -= c2(sz[x])
        } else {
            res[1] -= c2(n - sz[0])
        }
    }
    var almostLca = -1
    for (i in 1 until n) {
        if (u == v) {
            when {
                isPar(u, i) -> {
                    for (x in a[u]) {
                        if (x != par[u] && isPar(x, i)) {
                            almostLca = x
                        }
                    }
                    v = i
                }
                isPar(i, u) -> {
                    for (x in a[i]) {
                        if (x != par[i] && isPar(x, u)) {
                            almostLca = x
                        }
                    }
                    u = i
                }
                else -> {
                    almostLca = -1
                    v = i
                }
            }
        } else if (isPar(u, v)) {
            if (isPar(v, i)) {
                v = i
            } else if (isPar(i, u)) {
                for (x in a[i]) {
                    if (x != par[i] && isPar(x, u)) {
                        almostLca = x
                    }
                }
                u = i
            } else if (!isPar(almostLca, i)) {
                almostLca = -1
                u = i
            } else if (!isPar(u, i) || !isPar(i, v)) {
                break;
            }
        } else {
            if (isPar(u, i)) {
                u = i
            } else if (isPar(v, i)) {
                v = i
            } else if (isPar(i, u) && isPar(i, v)) {
                var ok = true
                for (x in a[i]) {
                    if (x != par[i] && isPar(x, u) && isPar(x, v)) {
                        ok = false
                    }
                }
                if (!ok) {
                    break
                }
            } else if (!isPar(i, u) && !isPar(i, v)) {
                break
            }
        }

        when {
            isPar(u, v) -> {
                res[i + 1] = 1L * sz[v] * (n - sz[almostLca])
            }
            isPar(v, u) -> {
                res[i + 1] = 1L * sz[u] * (n - sz[almostLca])
            }
            else -> {
                res[i + 1] = 1L * sz[u] * sz[v]
            }
        }
    }

    for (i in 0 until n) {
        res[i] -= res[i + 1]
    }
    println(res.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}