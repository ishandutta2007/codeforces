import kotlin.system.exitProcess

var G = mutableListOf(mutableListOf<Int>())
var vis = mutableListOf(mutableListOf<Boolean>())
var from = mutableListOf(mutableListOf<Int>())
var circle = false
var ins = mutableListOf(false)
fun DFS(u : Int, p : Int){
    vis[u][p] = true
    ins[u] = true
    for(v in G[u]){
        if(ins[v]) circle = true
        if(vis[v][1 - p] == false) {
            from[v][1 - p] = u;
            DFS(v, 1 - p)
        }
    }
    ins[u] = false
}
fun main(){
    var n = readLine()!!.split(' ')[0].toInt()
    for(i in 1..n){
        var s = readLine()!!.split(' ')
        G.add(mutableListOf())
        vis.add(mutableListOf(false, false))
        from.add(mutableListOf(0, 0))
        ins.add(false)
        for(j in 1 until  s.size) G[i].add(s[j].toInt())
    }
    var s = readLine()!!.toInt()
    DFS(s, 0)
    for(i in 1..n) if((G[i].size == 0) and (vis[i][1])){
        var st = mutableListOf<Int>()
        var t = i
        var p = 1
        while(true){
            st.add(t)
            if((t == s) and (p == 0)) break
            t = from[t][p]
            p = 1 - p
        }
        st.reverse()
        println("Win")
        for(x in st) print("$x ")
        exitProcess(0)
    }
    if(circle) print("Draw")
    else print("Lose")
}