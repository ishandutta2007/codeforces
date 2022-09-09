import kotlin.math.abs
import kotlin.math.min

fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(readInt()){
        val (n, k) = readLongs()
        val a = readLongs().withIndex().sortedByDescending{it.value}
        var l = a[0].value
        var r = a[0].value + k
        while(l < r){
            val m = (l + r) / 2
            var u = m
            var tk = k
            for(x in a){
                tk -= u - x.value
                u -= 1
            }
            if(tk <= 0) r = m
            else l = m + 1
        }
        val ans = LongArray(n.toInt())
        var tk = k
        var u = l
        for(x in a){
            val d = min(tk, u - x.value)
            tk -= d
            ans[x.index] = d
            u -= 1
        }
        for(x in ans) print("$x ")
        println()
    }
}