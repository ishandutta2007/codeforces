data class Edge(val u : Int, val v : Int, val w : Long)
fun main() {
    val (n, m) = readLine()!!.split(' ').map{it.toInt()}
    val a = readLine()!!.split(' ').map{it.toLong()}
    val x = a.indexOf(a.minOrNull())
    val edges = (Array(n){
            Edge(x, it, a[x] + a[it])
        } + Array(m){
            val (u, v, w) = readLine()!!.split(' ').map{it.toLong()}
            Edge(u.toInt() - 1, v.toInt() - 1, w)
        }).sortedBy{it.w}
    val par = Array(n){it}
    var ans = 0L
    fun getPar(u : Int) : Int{
        if(u == par[u]) return u
        par[u] = getPar(par[u])
        return par[u]
    }
    for((u, v, w) in edges){
        val pu = getPar(u)
        val pv = getPar(v)
        if(pu != pv) ans += w
        par[pu] = pv
    }
    println(ans)
}