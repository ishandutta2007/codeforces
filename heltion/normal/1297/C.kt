import kotlin.math.abs

fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val n = readInt()
        val a = readInts()
        val p = a.withIndex().minBy{if (it.value == 0) 100000 else abs(it.value)}!!.index
        val s = a.withIndex().map{
            var x = 0
            if(it.index == p){if(it.value < 0) x = 1}
            else{if(it.value > 0) x = 1}
            x
        }
        println(a.withIndex().sumBy{s[it.index] * it.value})
        for(x in s) print(x)
        println()
    }
}