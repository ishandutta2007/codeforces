import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()
var f = Array(320000){it}
fun nxt(u : Int) : Int{
    if(u == f[u]) return u
    f[u] = nxt(f[u])
    return f[u]
}
fun main(){
    var m = rdi()
    var b = rdis()
    var n = b.count({it == -1})
    var ans = Array(n + 1){ mutableListOf<Int>()}
    println(n)
    var i = 1
    for(x in b){
        if(x >= 0) ans[i].add(x)
        else{
            var j = nxt(if(i == n) 1 else i + 1)
            f[i] = j
        }
        i = nxt(if(i == n) 1 else i + 1)
    }
    for(j in 1..n){
        print("${ans[j].size} ")
        for(k in ans[j]) print("$k ")
        println("")
    }
}