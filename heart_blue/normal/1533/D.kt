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
    var mc = mutableMapOf<Long,Int>()
    for(kkk in 0 until n)
    {
        var str = readLn()
        var x:Long = 0L
        for(c in str)
        {
            x = x*26+c.toInt()-'a'.toInt()
        }
        mc[x] = -1
    }
    var q = readInt()
    for(kkk in 0 until q)
    {
        var str = readLn()
        var ans = 0
        for(i in 0..m)
        {
            var x:Long = 0
            for(j in 0..m)
            {
                if(i == j) continue
                x = x*26+str[j].toInt()-'a'.toInt()
            }
            if(mc.containsKey(x))
            {
                if(mc[x] != kkk)
                {
                    mc[x] = kkk
                    ans++
                }
            }
        }
        println(ans)
    }
}