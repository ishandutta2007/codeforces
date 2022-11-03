import java.util.*
import kotlin.Comparator

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
class BIT
{
    var a:IntArray = IntArray(0,{it})
    var sz:Int = 0
    fun init(n : Int)
    {
        a = IntArray(n+1,{it->0})
        sz = n
    }
    fun sum(x :  Int) : Int
    {
        var ret = 0
        var o = x
        while(o > 0)
        {
            ret = Math.max(ret,a[o])
            o -= o and -o
        }
        return ret
    }
    fun add(x : Int, y : Int)
    {
        var o = x
        while(o <= sz)
        {
            a[o] = Math.max(a[o],y)
            o += o and -o
        }
    }
}
fun main() {
    var ncase = readInt()
    for(oo in 0 until ncase)
    {
        var n = readInt()
        var vp = Array<Pair<Int,Int>> (n+1, {it->Pair<Int,Int>(-1,-1)})
        var a = readInts()
        for(i in 1..n)
        {
            var x = a[i-1]
            if(vp[x].first == -1)
                vp[x] = Pair<Int,Int>(i,-1)
            else
                vp[x] = Pair<Int,Int>(vp[x].first,i)
        }
        for(i in 1..n)
        {
            if(vp[i].second == -1)
                vp[i] = Pair<Int,Int>(-1,-1)
            else
            {
                if(vp[i].first > vp[i].second)
                    vp[i] = Pair<Int,Int>(vp[i].second,vp[i].first)
                vp[i] = Pair<Int,Int>(n-vp[i].first+1,vp[i].second)
            }
        }
        vp.sortWith(compareBy({it.first}))
        var b = BIT()
        b.init(n)
        var ans = 1
        for((x,y) in vp)
        {
            if(x == -1)
                continue
            var res1 = b.sum(y) + 2
            var res2 = 2
            if(n-x+1 < y-1)
                res2++
            b.add(y, Math.max(res1,res2))
            ans = Math.max(ans, b.sum(y))
        }
        println(ans)
    }
}