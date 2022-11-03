import java.util.*
import kotlin.Comparator


fun main() {
    var n = readLine()!!.toInt()
    var str = readLine()!!
    var ans:Int = 0
    for(i in 0..str.length)
    {
        if(i + 2 == str.length) break
        if(str[i] == str[i+1] && str[i+1] == str[i+2] && str[i] == 'x')
            ans++
    }
    println(ans)
}