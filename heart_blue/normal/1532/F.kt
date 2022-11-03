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
fun check(vs : Array<Pair<String,Int>>, s1 : String, s2 : String) : CharArray {
    var str = s1
    var s = s2.substring(s2.length-1,s2.length)
    str = str+s
    vs.sortWith(compareBy({it.first.length}))
    var ret : CharArray = CharArray(vs.size)
    for(i in 0 until vs.size step 2)
    {
        var len = i/2+1
        var s1 = vs[i].first
        var s2 = vs[i+1].first
        var pre = str.substring(0,len)
        var suf = str.substring(str.length-len,str.length)
        if(s1 == pre && s2 == suf)
        {
            ret[vs[i].second] = 'P'
            ret[vs[i+1].second] = 'S'
        }
        else if(s1 == suf && s2 == pre)
        {
            ret[vs[i].second] = 'S'
            ret[vs[i+1].second] = 'P'
        }
        else
        {
            return CharArray(0)
        }
    }
    return ret
}
fun main() {
    var n = readInt()
    var vs = Array<Pair<String,Int>> (2*n-2, {Pair("",0)})
    for(i in 0 until (2*n-2))
    {
        var str = readLn()
        vs[i] = Pair(str,i)
    }
    vs.sortWith(compareBy({it.first.length}))
    var str1 = vs[2*n-4].first
    var str2 = vs[2*n-3].first
    var ans1 = check(vs,str1,str2)
    var ans2 = check(vs,str2,str1)
    if(ans1.size > ans2.size) println(ans1)
    else println(ans2)
}