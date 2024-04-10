fun pow(a: Long, b: Int): Long = if (b == 0) 1 else a * pow(a, b - 1)

fun solve() {
    val line = readLine()!!.split(" ")
    val n = line[0].toInt()
    val x = line[1].toLong()
    val cache = mutableMapOf<Long, Int>()
    fun f(x: Long): Int {
        if (cache.containsKey(x)) {
            return cache[x]!!
        }
        val s = x.toString()
        if (s.length == n) {
            return 0
        }
        var res = -1
        val cands = s.toSet().toList().map { it - '0' }.sorted().reversed()
        for (c in cands) {
            if (c <= 1) {
                continue
            }
            val r = f(x * c) + 1
            if (r > 0 && (res > r || res == -1)) {
                res = r
            }
        }
        cache[x] = res
        return res
    }
    println(f(x))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}