fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }
    repeat (readInt()) {
        val n = readInt()
        val x = readInts()
        var ans = false
        for (i in 1 until n)
            if ((x[i] - x[i - 1]) % 2 == 0)
                ans = true
        println(if (ans) "YES" else "NO")
    }
}