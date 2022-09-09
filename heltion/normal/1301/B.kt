import kotlin.math.abs

fun main(){
    fun readInt() = readLine()!!.toInt()
    repeat(readInt()){
        val n = readInt()
        val a = readLine()!!.split(' ').map(String::toInt)
        val b = mutableListOf<Int>()
        for(i in 0 until n) if(a[i] == -1){
            if(i > 0 && a[i - 1] != -1) b.add(a[i - 1])
            if(i + 1 < n && a[i + 1] != -1) b.add(a[i + 1])
        }
        val k = if(b.isEmpty()) 0 else (b.max()!! + b.min()!!) / 2
        val c = a.map{if(it == -1) k else it}
        println("${(1 until n).map{abs(c[it] - c[it - 1])}.max()} $k")
    }
}