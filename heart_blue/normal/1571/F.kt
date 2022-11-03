private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
var pre = Array(5010, {-1})
var flag = Array(5010,{0})
fun main() {
    var (n,m) = readInts()
    var a = IntArray(5010)
    var ans = IntArray(n)
    var last = 0
    pre[0] = 0
    var tot = 0
    for(i in 1..n)
    {
        var (k,t) = readInts()
        if(t == 1)
        {
            flag[i-1] =1
            ans[i-1] = last+1
            last += k
        }
        else
        {
            tot += k
            a[i-1] = k
            for(j in m downTo k)
            {
                if(pre[j] == -1 && pre[j-k] >= 0)
                {
                    pre[j] = i-1
                }
            }
        }
    }
    if(last > m)
    {
        println(-1)
        return
    }
    last = last+1
    var rest1 = 0
    var rest2 = 0
    for(i in last..m)
    {
        if((i-last) % 2 == 0) rest1++
        else rest2++
    }
    var last1 = last
    var last2 = last+1
    var ok = 0
    for(i in rest1 downTo 1)
    {
        if(pre[i] != -1)
        {
            if(i + rest2 < tot)
                continue

            ok = 1
            var o = i
            while(o > 0)
            {
                var x = pre[o]
                ans[x] = last1
                last1 += a[x]*2
                flag[x] = 1
                o = o - a[x]
            }
            break
        }
    }
    if(tot == 0) ok = 1
    if(ok == 0)
    {
        println(-1)
        return
    }
    for(i in 0 until n)
    {
        if(flag[i] == 1)
            continue
        ans[i] = last2
        last2 += a[i]*2
    }
    println(ans.joinToString(" "))
}