import kotlin.system.exitProcess

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()
var d = Array(500000){0}
var g = Array(500000){0}
var w = Array(500000){0}
var v = Array(500000){0}
var vis = Array(500000){0}
var nxt = Array(500000){0}
var ed = 1
var ans1 = mutableListOf<Int>()
fun add(x : Int, y : Int, z : Int){
    d[x] += 1
    ed += 1
    v[ed] = y
    w[ed] = z
    nxt[ed] = g[x]
    g[x] = ed
}
fun dfs(x : Int){
    while(g[x] != 0){
        if(vis[g[x]] != 0){
            g[x] = nxt[g[x]]
            continue
        }
        vis[g[x]] = 1
        vis[g[x] xor 1] = 1
        var j = v[g[x]]
        d[x] -= 1
        d[v[g[x]]] -= 1
        dfs(v[g[x]])
        ans1.add(j)
    }
}
fun main(){
    var (n, m) = rdis()
    for(i in 1..m){
        var (x, y) = rdis()
        add(x, y, i)
        add(y, x, -i)
    }
    for(i in 1..n) if(d[i] % 2 == 1){
        print("NO")
        exitProcess(0)
    }
    for(i in 1..n) if(d[i] != 0) {
        dfs(i)
        ans1.add(i)
    }
    var ans = mutableListOf<MutableList<Int>>()
    var stack = Array(500000){0}
    var top = 0
    var ms = mutableSetOf<Int>()
    for(x in ans1){
        if(ms.contains(x)){
            ans.add(mutableListOf())
            ans[ans.size  - 1].add(x)
            while(true){
                ans[ans.size  - 1].add(stack[top])
                ms.remove(stack[top])
                top -= 1
                if(stack[top + 1] == x) break
            }
        }
        top += 1
        stack[top] = x
        ms.add(x)
    }
    println("YES")
    println(ans.size)
    for(a in ans){
        print("${a.size} ")
        for(x in a) print("$x ")
        println("")
    }
}