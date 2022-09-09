fun main(){
    var s = readLine()!!.split(' ').map{it.toInt()}
    var (n, m) = s
    var ans = Array(n + 1){ mutableListOf<Int>()}
    for(i in 1..m){
        s = readLine()!!.split(' ').map{it.toInt()}
        var (u, v) = s
        ans[u].add(i)
        ans[v].add(i)
    }
    var c = m
    for(i in 1..n){
        if(ans[i].none()){
            c += 1
            println("1\n$i $c")
        }
        else{
            println(ans[i].size)
            for(p in ans[i])
                println("$i $p")
        }
    }
}