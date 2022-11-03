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
    var n = readInt()
    var a = readInts().toIntArray()
    var b = readInts().toIntArray()
    var lmax = Array(n+10, {-1000000000 })
    var rmax = Array(n+10, {-1000000000 })
    a.sort()
    b.sort()
    for(i in 0 until n)
    {
        lmax[i] = b[i] - a[i]
        rmax[i+1] = b[i+1] - a[i]
    }
    for(i in 1..n)
    {
        lmax[i] = maxOf(lmax[i],lmax[i-1])
        var j = n-i
        rmax[j] = maxOf(rmax[j],rmax[j+1])
    }
    var m = readInt()
    var c = readInts()
    var qr = Array<Pair<Int,Int>>(m,{Pair(0,0)})
    for(i in 0 until m)
    {
        qr[i] = Pair(c[i],i)
    }
    qr.sortWith(compareBy({it.first},{it.second}))
    var ans = IntArray(m)
    var ptr = 0
    for(i in 0 until m)
    {
        while(ptr < n && a[ptr] < qr[i].first)
            ptr++
        var res = b[ptr] - qr[i].first
        if(ptr > 0) res = maxOf(res, lmax[ptr-1])
        if(ptr < n) res = maxOf(res,rmax[ptr+1])
        ans[qr[i].second] = res
    }
    println(ans.joinToString(" "))
}