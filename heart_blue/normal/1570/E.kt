private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main() {
    var ncase = readInt()
    while (ncase-- > 0) {
        var str = readLn()
        var l = 100000000
        var r = 0
        var cnt = 0
        for (i in 0 until str.length) {
            if (str[i] == '1') {
                cnt++
                l = Math.min(l, i)
                r = Math.max(r, i)
            }
        }
        var ans = (r-l+1)-cnt
        ans = Math.max(0,ans)
        println(ans)
    }
}