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
    var str = readLn()
    var n = str.length
    var cnt0 = IntArray(n+10,{0})
    var cnt1 = IntArray(n+10,{0})
    for(i in 1..n)
    {
        cnt0[i] = cnt0[i-1]
        cnt1[i] = cnt1[i-1]
        if(str[i-1] == '0')
        {
            cnt0[i]++
        }
        else
        {
            cnt1[i]++
        }
    }
    var ans = mutableListOf<Int>()
    for(i in 1..n)
    {
        var cur = 1
        var res = 0
        while(cur <= n)
        {
            res++
            var l = cur
            var r = n
            var key = cur
            while(l <= r)
            {
                var mid = (l+r)/2
                if(cnt0[mid] -cnt0[cur-1] <= i || cnt1[mid] - cnt1[cur-1] <= i) {
                    key = mid
                    l = mid+1
                }
                else
                {
                    r = mid-1
                }
            }
            cur = key+1
        }
        ans.add(res)
    }
    println(ans.joinToString(" "))
}