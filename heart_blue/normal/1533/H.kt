private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
var flag = Array(110, { IntArray(110) })
var bomb = Array(110, { IntArray(110) })
var vs = Array<String>(110, { String() })
var n: Int = 0
var m: Int = 0
var dx = arrayOf(-1, 1, 0, 0)
var dy = arrayOf(0, 0, -1, 1)
var ddx = arrayOf(1, 1, 1, -1, -1, -1, 0, 0)
var ddy = arrayOf(-1, 1, 0, -1, 1, 0, -1, 1)

// v.sortWith(compareBy({it.first},{it.second}))
fun isValid(x: Int, y: Int): Boolean {
    if (x < 0 || x == n || y < 0 || y >= m || flag[x][y] == 1) return false
    else return true
}

fun getcnt(x: Int, y: Int): Int {
    var cnt = 0
    for (i in 0 until 8) {
        var tx = x + ddx[i]
        var ty = y + ddy[i]
        if (tx < 0 || tx == n || ty < 0 || ty >= m) continue
        cnt += flag[tx][ty]
    }
    return cnt
}

fun dis(x1: Int, y1: Int, x2: Int, y2: Int): Int {
    return Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1))
}
fun main() {
    var (n,m) = readInts()
    var vs = Array<String>(n, { readLn() })
    var cnt = IntArray(32,{0})
    for(i in 1 until 32)
    {
        cnt[i] = cnt[i/2] + (i%2)
    }
    var v = LongArray(32,{0L})
    var ans = LongArray(5,{0})
    for(o in 1 until 32) {
        var U = IntArray(m+10,{0})
        var S = IntArray(m+10,{0})
        var c = Array(n+10,{IntArray(m+10,{0})})
        for (i in 0 until n) {

            for (j in 0 until m) {
                var x = vs[i][j].toInt() - 'A'.toInt()
                x = 1 shl x
                if((x and o) == 0) U[j+1] = 0
                else U[j+1] ++
            }
            var cur = 0
            S[++cur] = 0
            for(j in 1..(m+1))
            {
                while ( U[j] < U[S[cur]] ) {
                    c[maxOf ( U[S[cur - 1]] , U[j] ) + 1][j - S[cur - 1] - 1] ++ ;
                    c[U[S[cur]] + 1][j - S[cur - 1] - 1] -- ;
                    -- cur ;
                }
                while ( cur >= 1 && U[j] == U[S[cur]] ) -- cur ;
                S[++ cur] = j ;
            }

        }
        for (i in 1..n) {
            for (j in 1..m) c[i][j] += c[i - 1][j]
        }
        for (i in 1..n) {
            for (j in m - 1 downTo 1) c[i][j] += c[i][j + 1]
            for (j in m - 1 downTo 1) c[i][j] += c[i][j + 1]
        }
        var res:Long = 0
        for (i in 1..n) {
            for (j in 1..m) {
                res += c[i][j]
            }
        }
        v[o] = res
    }
    for(i in 1 until 32)
    {
        for(j in 1 until i)
        {
            if((i and j) == j)
            {
                v[i] = v[i] - v[j]
            }
        }
        var k = cnt[i] - 1
        ans[k] = ans[k] + v[i]
    }
    println(ans.joinToString(" "))
}