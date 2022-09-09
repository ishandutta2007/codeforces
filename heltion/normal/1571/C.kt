fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat(readInt()) {
        val n = readInt()
        var l = 0
        var r = 200000
        repeat(n) {
            val line = readLine()!!.split(' ')
            val s = line[0]
            val t = line[1]
            val ri = line[2].toInt()
            var k = 0
            while (k < s.length && k < t.length && s[s.length - k - 1] == t[t.length - k - 1])
                k += 1
            if (ri == 0) l = maxOf(l, k + 1)
            else r = minOf(r, k)
        }
        if (l > r) println(0)
        else {
            println(r - l + 1)
            for(i in l..r) print("$i ")
            println()
        }
    }
}