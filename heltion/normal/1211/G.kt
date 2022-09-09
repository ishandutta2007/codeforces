var G = Array(240000){ mutableListOf<Int>()}
var dep = Array(240000){0}
var par = Array(240000){0}
var cnt = Array(240000){0}
var vis = Array(240000){0}
var era = Array(240000){0}
data class pr(var id : Int, var dep : Int)
var diff = mutableListOf<pr>()
var sz = Array(240000){0}
var mnd = 0
fun DFS(u : Int){
    if(vis[u] > 0) sz[u] = 1
    else sz[u] = 0
    var cnt = 0
    for(v in G[u]) if(v != par[u]){
        par[v] = u
        dep[v] = dep[u] + 1
        DFS(v)
        if(sz[v] > 0) cnt += 1
        sz[u] += sz[v]
    }
    if(cnt > 1) if(vis[u] == 0){
        diff.add(pr(u, dep[u]))
        vis[u] = 1
        mnd = minOf(mnd, dep[u])
    }
    if(cnt == 1) if(vis[u] == 0) if(dep[u] > mnd){
        diff.add(pr(u, dep[u]))
        vis[u] = 1
        mnd = minOf(mnd, dep[u])
    }
}
fun main() {
    var t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt()
        var c = readLine()!!.split(' ').map{it.toInt()}
        var d = readLine()!!.split(' ').map{it.toInt()}
        for(i in 1..n){
            G[i].clear()
            cnt[i] = 0
            vis[i] = 0
            era[i] = 0
        }
        for(i in 1 until n) {
            var (u, v) = readLine()!!.split(' ').map { it.toInt() }
            G[u].add(v)
            G[v].add(u)
        }
        diff.clear()
        mnd = 2400000
        DFS(1)
        for(i in 0 until n) if(d[i] != c[i]){
            diff.add(pr(i + 1, dep[i + 1]))
            vis[i + 1] = 1
            mnd = minOf(mnd, dep[i + 1])
        }
        DFS(1)
        DFS(1)
        if(diff.isEmpty()){
            println("YES\n0")
            continue
        }
        diff = diff.sortedBy { it.dep }.toMutableList()
        var ok = 1
        for(i in 0 until diff.size){
            //println(diff[i])
            if((i > 0) and (vis[par[diff[i].id]] == 0)){
                ok = 0
            }
            cnt[par[diff[i].id]] += 1
        }
        for(i in 1..n) {
            if((cnt[i] > 1) and (i != diff[0].id)) ok = 0
            if((cnt[i] > 2)) ok = 0
        }
        if(ok == 0){
            println("NO")
            continue
        }
        var road = mutableListOf<Int>()
        if(diff.size == 1){
            println("NO")
            continue
        }
        var u = diff[diff.size - 1].id
        while(u != diff[0].id){
            road.add(u)
            era[u] = 1
            u = par[u]
        }
        road.add(diff[0].id)
        if(cnt[diff[0].id] == 2){
            var road2 = mutableListOf<Int>()
            var x = diff.size - 1
            while(era[diff[x].id] == 1) x -= 1
            u = diff[x].id
            while(u != diff[0].id){
                road2.add(u)
                era[u] = 1
                u = par[u]
            }
            for(i in road2.size - 1 downTo 0) road.add(road2[i])
        }
        var pok = 1
        for(i in 0 until road.size){
            if(d[road[i] - 1] != c[road[(i + 1) % road.size] - 1]) pok = 0
        }
        if(pok == 1){
            println("YES\n${road.size}")
            for(x in road) print("$x ")
            print("\n")
            continue
        }
        pok = 1
        road.reverse()
        for(i in 0 until road.size){
            if(d[road[i] - 1] != c[road[(i + 1) % road.size] - 1]) pok = 0
        }
        if(pok == 1){
            println("YES\n${road.size}")
            for(x in road) print("$x ")
            print("\n")
            continue
        }
        println("NO")
    }
}