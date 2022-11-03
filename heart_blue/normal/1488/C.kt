import java.util.*
import kotlin.Comparator

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var ncase = readInt()
    for(oo in 0 until ncase)
    {
        var (n, x, y) = readInts()
        if(x > y) x = y.apply({y= x})
        if(x + 1 == y)
        {
            println(Math.max(x-1,n-y))
            continue
        }
        var ans = 1000000000
        var l = Math.max(x-1,n-y)
        var r = ans
        while(l <= r)
        {
            var mid = (l+r)/2;
            var curl = Math.max(mid-(x-1)+1, x + (mid-(x-1))/2)
            var t = n - y + 1
            var curr = Math.max(mid-(t-1)+1, t + (mid-(t-1))/2)
            curr = n-curr+1;
            if(curl +1 >= curr) {
                ans = mid
                r = mid - 1
            }
            else
            {
                l = mid+1
            }
        }
        println(ans)

    }
}