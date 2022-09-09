fun main(){
    var t = readLine()!!.toInt()
    for(i in 0 until  t){
        var s  = readLine()
        var n = s!!.length
        var p = 0
        for(i in 1 until n) if(s[i] != s[0]) p = i
        if(p == 0) println(-1)
        else{
            for(i in 0 until n - 1){
                if(i != p) print(s[i])
                else if(i == p) print(s[n - 1])
            }
            println(s[p])
        }
    }
}