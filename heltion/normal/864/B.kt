import java.lang.Math.max

fun main(){
    readLine()
    var s = readLine()!!
    var ans = 0
    var ss = mutableSetOf<Char>()
    for(c in s){
        if(c < 'a') ss.clear()
        else ss.add(c)
        ans = max(ans, ss.size)
    }
    print(ans)
}