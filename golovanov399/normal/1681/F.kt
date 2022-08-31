data class Edge(val v: Int, val x: Int)

data class Info(var before: Int, var onlyOne: Int) {
    fun update(other: Info) {
        before += other.before
        onlyOne += other.onlyOne
    }

    fun shift() {
        onlyOne = before
        before = 0
    }
}

class State() {
    var sumOnlyOne = 0L
    var size = 1
    var addToBefore = 0
    val map = mutableMapOf<Int, Info>()

    fun normalize() {
        for ((key, info) in map) {
            info.before += addToBefore
        }
        addToBefore = 0
    }

    fun update(other: State): Long {
        var ans = sumOnlyOne * other.size
        for ((key, info) in other.map) {
            if (map.containsKey(key)) {
                val old = map[key]!!
                ans -= (other.size - info.before) * old.onlyOne.toLong()
                ans += (old.before + addToBefore).toLong() * info.onlyOne
                old.update(info)
                old.before -= other.size
            } else {
                ans += size * info.onlyOne.toLong()
                map[key] = Info(info.before + size - addToBefore - other.size, info.onlyOne)
            }
        }
        addToBefore += other.size
        sumOnlyOne += other.sumOnlyOne
        size += other.size
        return ans
    }

    fun shiftInfo(x: Int) {
        if (map.containsKey(x)) {
            val info = map[x]!!
            sumOnlyOne -= info.onlyOne
            info.before += addToBefore
            info.shift()
            info.before -= addToBefore
            sumOnlyOne += info.onlyOne
        } else {
            map[x] = Info(-addToBefore, size)
            sumOnlyOne += size
        }
    }

    override fun toString(): String {
        return "(sumOnlyOne = $sumOnlyOne, size = $size, map = $map, addToBefore = $addToBefore)"
    }
}

fun solve() {
    val n = readLine()!!.toInt()
    val a = List(n) { mutableListOf<Edge>() }
    repeat (n - 1) {
        val (u, v, x) = readLine()!!.split(" ").map(String::toInt)
        a[u - 1].add(Edge(v - 1, x))
        a[v - 1].add(Edge(u - 1, x))
    }
    var ans = 0L
    val m = List(n) { State() }
    val mapIndex = MutableList(n) { it }
    fun dfs(v: Int, p: Int) {
        for ((u, x) in a[v]) {
            if (u == p) {
                continue
            }
            dfs(u, v)
            m[mapIndex[u]].shiftInfo(x)
            if (m[mapIndex[u]].size > m[mapIndex[v]].size) {
                mapIndex[u] = mapIndex[v].also { mapIndex[v] = mapIndex[u] }
            }
            m[mapIndex[u]].normalize()
            ans += m[mapIndex[v]].update(m[mapIndex[u]])
        }
    }
    dfs(0, -1)
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}