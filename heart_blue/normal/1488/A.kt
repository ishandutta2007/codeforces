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
    repeat(ncase)
    {
        var (x,y) = readLongs()
        var o:Long = 1000000000
        var ans:Long = 0
        for(i in 1.. 100)
        {
            if(o.toInt() == 0) break
            ans += y/(x*o)
            y %= x*o
            o /= 10L
        }
        ans += y
        println(ans)
    }
}