import java.util.*
import kotlin.Comparator

fun main() {
    var n = readLine()!!.toInt()
    var vs = mutableListOf<String>()
    for(i in 1..n)
    {
        var str = readLine()!!
        vs.add(str)
    }
    val ans = vs.toTypedArray()
    ans.sortWith(compareBy({it.length}))
    for(i in ans.indices)
    {
        if(i == 0) continue
        if(!ans[i].contains(ans[i-1]))
        {
            println("NO")
            return
        }
    }
    println("YES")
    for(s in ans)
        println(s)
}