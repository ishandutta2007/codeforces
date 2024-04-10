fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(readInt()){
        val (n, k, x, y) = readLongs()
        val a = readLongs().sortedDescending()
        var sum = a.sum()
        var ans = n * x
        var pans = 0L
        for(z in a){
            if(z <= k) ans = minOf(ans, pans)
            if(sum <= k * n) ans = minOf(ans, pans + y)
            sum -= z
            pans += x
        }
        println(ans)
    }
}