private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
var dp = Array(200010, { IntArray(16) })
fun main() {
    var ncase = readInt()
    while (ncase-- > 0) {
        var n = readInt()
        var str = readLn()
        var a = readLn()
        var limit = 1000000000
        for (o in 0 until 16) dp[0][o] = limit
        var k1 = 12
        var k2 = 10
        for (o in 0 until 16) {
            if (a[0] == '1')
            {
                if(o != k1 && o != k2)
                    continue
            }
            var cnt = 0
            for (k in 0 until 4) {
                if (o.shr(k) % 2 == 1) {
                    if (str[k] == '(') cnt++
                } else {
                    if (str[k] == ')') cnt++
                }
            }
            dp[0][o] = cnt
        }
        for (i in 1 until a.length) {
            for (o in 0 until 16)
                dp[i][o] = limit
            for (o1 in 0 until 16) {
                for (o2 in 0..1) {
                    var o = o1 / 2 + o2 * 8
                    if (a[i] == '1')
                    {
                        if(o != k1 && o != k2)
                            continue
                    }
                    var cnt = 0
                    if (str[i + 3] == '(' && o2 == 1)
                        cnt = 1
                    if (str[i + 3] == ')' && o2 == 0)
                        cnt = 1
                    dp[i][o] = Math.min(dp[i][o], dp[i - 1][o1] + cnt)
                }
            }
        }
        var ans = limit
        for (o in 0 until 16)
            ans = Math.min(ans, dp[a.length - 1][o])
        if (ans == limit)
            ans = -1
        println(ans)
    }
}