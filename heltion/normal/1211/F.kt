var n = 0
var m = 0
var i = 0
var x = 0
var y = 0
var d = Array(7){0}
var g = Array(7){0}
var v = Array(240000){0}
var vis = Array(240000){0}
var nxt = Array(240000){0}
var ed = 0
var ans = mutableListOf<Int>()
fun add(x : Int, y : Int){
    d[x] += 1
    d[y] -= 1
    ed += 1
    v[ed] = y
    nxt[ed] = g[x]
    g[x] = ed
}
fun dfs(x : Int){
    while(g[x] > 0) {
        if (vis[g[x]] > 0) {
            g[x] = nxt[g[x]]
            continue
        }
        vis[g[x]] = 1
        var j = g[x]
        dfs(v[g[x]])
        ans.add(j)
    }
}
fun main() {
    var k = readLine()!!.toInt()
    repeat(k){
        var s = readLine()!!
        var x = 0
        var y = 0
        if(s[0] == 'k') x = 1
        if(s[0] == 'o') x = 2
        if(s[0] == 't') x = 3
        if(s[0] == 'l') x = 4
        if(s[0] == 'i') x = 5
        if(s[0] == 'n') x = 6
        if(s[s.length - 1] == 'k') y = 2
        if(s[s.length - 1] == 'o') y = 3
        if(s[s.length - 1] == 't') y = 4
        if(s[s.length - 1] == 'l') y = 5
        if(s[s.length - 1] == 'i') y = 6
        if(s[s.length - 1] == 'n') y = 1
        add(x, y)
    }
    dfs(1)
    for(i in ans.size - 1 downTo 0) print("${ans[i]} ")
}