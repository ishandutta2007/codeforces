fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val n = readInt()
    val a = readInts().sorted().toIntArray()
    val b = readInts().sorted().toIntArray()
    val pre = IntArray(n){
        b[it] - a[it]
    }
    val suf = IntArray(n) {
        b[it + 1] - a[it]
    }
    for (i in 1 until n) pre[i] = maxOf(pre[i], pre[i - 1])
    for (i in n - 2 downTo 0) suf[i] = maxOf(suf[i], suf[i + 1])
    readInt()
    for(c in readInts()){
        var l = 0
        var r = n
        while (l < r) {
            val m = (l + r) / 2
            if (a[m] <= c) l = m + 1
            else r = m
        }
        when(l){
            0 -> print(maxOf(b[0] - c, suf[0]))
            n -> print(maxOf(b[n] - c, pre[n - 1]))
            else -> print(maxOf(b[l] - c, pre[l - 1], suf[l]))
        }
        print(" ")
    }
}