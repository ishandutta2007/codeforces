fun main(){
    val (n, k) = readLine()!!.split(' ').map{it.toInt()}
    val ans = IntArray(n)
    val r = readLine()!!.split(' ').map{it.toInt()}
    repeat(k){
        val (x, y) = readLine()!!.split(' ').map{it.toInt() - 1}
        if(r[x] < r[y]) ans[y] -= 1
        if(r[x] > r[y]) ans[x] -= 1
    }
    val p = Array(n){Pair(it, r[it])}.sortedBy{it.second}
    var x = 0
    for(i in 0 until n){
        if(i != 0 && p[i].second == p[i - 1].second) x += 1
        else x = 0
        ans[p[i].first] += i - x
    }
    for(x in ans) println(x)
}