import java.util.*
import kotlin.Comparator

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private var sumv = Array<Long>(800000+10, {it-> 0L})
private var setv = Array<Int>(800000+10,{it->0})
internal fun pushdown(o : Int, l : Int, r : Int)
{
    var o1 = o+o
    var o2 = o+o+1
    var mid = (l+r)/2
    if(setv[o] != 0)
    {
        setv[o1] = setv[o]
        setv[o2] = setv[o]
        sumv[o1] = setv[o].toLong()*(mid-l+1)
        sumv[o2] = setv[o].toLong()*(r-mid)
        setv[o] = 0
    }
}
internal fun maintain(o : Int)
{
    sumv[o] = sumv[o+o]+sumv[o+o+1]
}
fun update(l : Int, r : Int, ql : Int, qr : Int, qx : Int, o : Int)
{
    if(ql <= l && r <= qr)
    {
        setv[o] = qx
        sumv[o] = qx.toLong()*(r-l+1)
        return
    }
    var mid = (l+r)/2
    pushdown(o, l, r)
    if(ql <= mid) update(l, mid, ql, qr, qx, o+o)
    if(mid < qr) update(mid+1, r, ql, qr, qx, o+o+1)
    maintain(o)
}
fun query(l : Int, r : Int, ql : Int, qr : Int, o : Int) : Long
{
    if(ql <= l && r <= qr)
    {
        return sumv[o]
    }
    pushdown(o,l,r)
    var mid = (l+r)/2
    var res1 = 0L
    var res2 = 0L
    if(ql <= mid) res1 = query(l, mid, ql, qr, o+o)
    if(mid < qr) res2 = query(mid+1, r, ql, qr, o+o+1)
    return res1+res2
}
fun main() {
    var n = readInt()
    var a = readInts()
    var q = readInt()
    var ans = Array<Long> (q, {it->0L})
    var vp = Array<Triple<Int, Int, Int>> (q, {it->Triple(0,0,0)})
    for(i in 0 until q)
    {
        var (l,r) = readInts()
        vp[i] = Triple(l-1,r-1,i)
    }
    vp.sortWith(compareBy({(it.second)}))
    var len = n-1
    var ptr = 0
    var ls = mutableListOf<Pair<Int, Int>>()
    ls.add(Pair(0,1000000000))
    for(p in vp)
    {
        var (l,r,pos) = p
        while(ptr <= r)
        {
            var sz = 1
            while(a[ptr] >= ls.last().second)
            {
                sz += ls.last().first
                ls.removeLast()
            }
            update(0,len, ptr - sz+1,ptr, a[ptr],1)
            ls.add(Pair(sz,a[ptr++]))
        }
        ans[pos] = query(0,len,l,r,1)
    }
    for(x in ans)
        print("$x ")
}