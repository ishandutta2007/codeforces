import kotlin.math.abs

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    repeat(readInt()){
        val n = readInt()
        val a = readInts().withIndex().sortedBy{it.value}
        val b = readInts().withIndex().sortedBy{it.value}
        var axs = 0
        var ansk = 1
        for(k in 1..n){
            var pans = 1000000
            for(i in 0 until k) pans = minOf(pans, abs(a[i].value - b[n - k + i].value))
            for(i in k until n) pans = minOf(pans, abs(a[i].value - b[i - k].value))
            if(pans > axs){
                axs = pans
                ansk = k
            }
        }
        val ans = IntArray(n)
        for(i in 0 until ansk) ans[a[i].index] = b[n - ansk + i].index
        for(i in ansk until n) ans[a[i].index] = b[i - ansk].index
        for(x in ans) print("${x + 1} ")
        println()
    }
}