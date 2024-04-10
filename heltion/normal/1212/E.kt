data class Book(var c : Int, var p : Int, var id : Int)
data class Table(var r : Int, var id : Int)
fun main() {
    var n = readLine()!!.toInt()
    var a = mutableListOf<Book>()
    for(i in 1..n){
        var cp = readLine()!!.split(' ').map{it.toInt()}
        a.add(Book(cp[0], cp[1], i))
    }
    var m = readLine()!!.toInt()
    var r = readLine()!!.split(' ').map{it.toInt()}
    var vis = Array(m){false}
    a.sortWith(compareBy({-it.p}, {it.c}))
    var ans = 0
    var ansp = mutableListOf<Pair<Int, Int>>()
    for(b in a) {
        var mi = -1
        for (i in 0 until m) if(!vis[i] and (r[i] >= b.c)){
            if(mi == -1) mi = i
            else if(r[i] < r[mi]) mi = i
        }
        if(mi != -1){
            ans += b.p
            vis[mi] = true
            ansp.add(Pair(b.id, mi + 1))
        }
    }
    println("${ansp.size} $ans")
    for(p in ansp) println("${p.first} ${p.second}")
}