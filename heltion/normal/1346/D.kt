data class Edge(val u : Int, val v : Int, val w : Int)
fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(readInt()){
        val (n, m) = readInts()
        val a = Array(n + 1){-1}
        val edges = Array(m){
            val (u, v, w) = readInts()
            Edge(u, v, w)
        }.sortedByDescending{it.w}
        var ok = true
        for(edge in edges){
            if(a[edge.u] == -1) a[edge.u] = edge.w
            if(a[edge.v] == -1) a[edge.v] = edge.w
            if(minOf(a[edge.u], a[edge.v]) != edge.w) ok = false
        }
        if(ok){
            println("YES")
            for(i in 1..n) print("${a[i]} ")
            println()
        }else println("NO")
    }
}