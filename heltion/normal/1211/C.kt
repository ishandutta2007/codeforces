data class IceCream(val a : Long, val b : Long, val c : Long)
fun main(){
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    var (n, k) = readLongs()
    val iceCreams = Array(n.toInt()){
        val (a, b, c) = readLongs()
        IceCream(a, b, c)
    }.sortedBy{it.c}
    if(k < iceCreams.map{it.a}.sum() || k > iceCreams.map{it.b}.sum()) print(-1)
    else{
        k -= iceCreams.map{it.a}.sum()
        var ans = iceCreams.map{it.a * it.c}.sum()
        for(it in iceCreams){
            val d = minOf(it.b - it.a, k)
            k -= d
            ans += d * it.c
        }
        print(ans)
    }
}