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
        var (n, s) = readLongs()
        var l:Long = 1
        var r:Long = s
        var maxv:Long = r
        var ans:Long = 0
        while(l <= r)
        {
            var mid = (l+r)/2;
            var sum:Long = 0
            var o = n
            var cur = mid
            for(i in n downTo 1L)
            {
                if(cur == 1L)
                {
                    sum += i
                    break
                }
                if(sum > s)
                    break
                sum += cur
                cur = (cur+1)/2
            }
            if(sum > s) r = mid-1
            else
            {
                l = mid+1
                ans = mid
            }
        }
        println(ans)
    }
}