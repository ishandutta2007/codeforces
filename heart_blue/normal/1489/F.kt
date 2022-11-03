import java.util.*
import kotlin.Comparator

fun main() {
    var key = readLine()!!.split(" ").map(String::toInt)
    var a = readLine()!!.split(" ").map(String::toInt).toIntArray()
    var n = key[0]
    var m = key[1]
    var k = key[2]
    var ans = n
    var l = 0
    var r = n-1
    while(l <= r)
    {
        var mid = (l+r)/2
        var cost = 0
        var rest = 0
        for(i in mid until n)
        {
            if(rest < a[i])
            {
                rest = k
                cost++
            }
            rest -= a[i]
        }
        if(cost > m)
        {
            l = mid+1
        }
        else
        {
            r = mid-1
            ans = mid
        }
    }
    println("${n-ans}")
}