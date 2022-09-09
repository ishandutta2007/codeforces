fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val (n, m) = readInts()
    val g = Array(m + 1) { mutableListOf<Pair<Int, Int>>()}
    for (i in 1..n) {
        val k = readInt()
        val a = readInts()
        val b = readInts()
        for (j in 0 until k)
            g[b[j]].add(Pair(i, a[j]))
    }
    val inf = 300000000000000L
    val bit = LongArray(m + n + 2){-inf}
    var x = m + 1
    while (x <= m + n + 1) {
        bit[x] = 0L
        x += x and -x
    }
    var ans = 0L
    for (b in m downTo 0)
        for ((index, a) in g[b]) {
            var dp = -inf
            var x = index + b
            while (x > 0) {
                dp = maxOf(dp, bit[x])
                x -= x and -x
            }
            dp += a
            //println("$index $a $b $dp")
            ans = maxOf(ans, dp)
            x = index + b + 1
            while (x <= m + n + 1) {
                bit[x] = maxOf(bit[x], dp)
                x += x and -x
            }
        }
    println(ans)
}