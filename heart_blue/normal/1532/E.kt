private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
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
    var v = Array<Pair<Int,Int>>(n, {Pair(0,0)})
    var sum = 0L
    for(i in 0 until n) {
        v[i] = Pair(a[i],i+1)
        sum += a[i]
    }
    var ans :MutableList<Int> = ArrayList()
    v.sortWith(compareBy({it.first},{it.second}))
    for(i in 0 until n-1)
    {
        if(v[n-1].first*2L == sum - v[i].first)
            ans.add(v[i].second)
    }
    if(v[n-2].first*2L == sum - v[n-1].first)
        ans.add(v[n-1].second)
    println(ans.size)
    for(x in ans)
    {
        print(x)
        print(' ')
    }
}