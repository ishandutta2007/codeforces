fun main() {
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }
    repeat (readLine()!!.toInt()) {
        val (n, k) = readInts()
        var ans = 0
        repeat (n) {
            val (l, r) = readInts()
            if (l <= k)
                ans = maxOf(ans, r - maxOf(l, k) + 1)
        }
        println(ans)
    }
}