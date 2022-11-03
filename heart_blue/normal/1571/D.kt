private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var flag = Array(1100, { IntArray(1100) })
var flag1 = Array(1100, { 0 })
var flag2 = Array(1100, { 0 })
fun main() {
    var (n, m) = readInts()
    var kf = 0
    var kl = 0
    for (i in 1..m) {
        var (f, l) = readInts()
        if (kf == 0) {
            kf = f
            kl = l
        }
        flag[f][l]++
        flag1[f]++
        flag2[l]++
    }
    var ans = 0
    for (i in 1..n) {
        for (j in 1..n) {
            if (i == j)
                continue
            var x = 0
            var y = flag[i][j]
            var z = flag1[i] + flag2[j] - flag[i][j]
            if(i == kf && j == kl)
                ans = Math.max(ans,1)
            else if(i == kf || j == kl)
                ans = Math.max(ans, y+1)
            else
                ans = Math.max(ans, z+1)
        }
    }
    println(ans)
}