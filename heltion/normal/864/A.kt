import kotlin.system.exitProcess

fun main(){
    var n = readLine()!!.toInt()
    var mp = mutableMapOf<Int, Int>()
    for(i in 1..n){
        var a = readLine()!!.toInt()
        if(mp.contains(a)) mp.set(a, mp[a]!! + 1)
        else mp.set(a, 1)
    }
    if(mp.size == 2){
        var s = mp.values.toList()
        if(s[0] == s[1]){
            println("YES")
            s = mp.keys.toList()
            print("${s[0]} ${s[1]}");
            exitProcess(0)
        }
    }
    print("NO")
}