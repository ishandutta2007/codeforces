
import java.util.*
import kotlin.Comparator


fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).toIntArray()
    val ans = mutableListOf<Int>()
    val mc = sortedMapOf<Int,Int>()
    a.reverse()
    for(x:Int in a) {
        if(mc.getOrDefault(x,0) == 0)
        {
            mc[x] = 1
            ans.add(x)
        }
    }
    ans.reverse()
    println(ans.size)
    for(x in ans)
    {
        print("$x ")
    }
}