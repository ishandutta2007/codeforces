fun main(){
    var (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    if(k > 4 * n * m - 2 * n - 2 * m) print("NO")
    else{
        println("YES")
        val fans = mutableListOf<Pair<Int, String>>()
        repeat(m - 1){
            if(n > 1) fans.add(Pair(n - 1, "DRL"))
            if(n > 1) fans.add(Pair(n - 1, "U"))
            fans.add(Pair(1, "R"))
        }
        if(n > 1) fans.add(Pair(n - 1, "D"))
        if(n > 1) fans.add(Pair(n - 1, "U"))
        if(m > 1) fans.add(Pair(m - 1, "L"))
        val ans = mutableListOf<Pair<Int, String>>()
        var last = Pair(0, "")
        for(p in fans)
            if(p.first * p.second.length <= k) {
                k -= p.first * p.second.length
                ans.add(p)
            }
            else{
                last = p
                break
            }
        if(k > 0 && k / last.second.length >= 1){
            ans.add(Pair(k / last.second.length, last.second))
            k %= last.second.length
        }
        if(k > 0) ans.add(Pair(1, last.second.substring(0, k)))
        println(ans.size)
        for(p in ans) println("${p.first} ${p.second}")
    }
}