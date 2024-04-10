fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(1){
        val (n, m, k) = readInts()
        val a = Array(n + 1){if(it == k) 0 else -1}
        repeat(m){
            val (x, y) = readInts()
            val ax = a[x]
            val ay = a[y]
            if(ax == -1 && ay != -1){
                a[x] = ay
                a[y] = ay + 1
            }
            if(ay == -1 && ax != -1){
                a[x] = ax + 1
                a[y] = ax
            }
            if(ax != -1 && ay != -1){
                a[x] = minOf(ay, ax + 1)
                a[y] = minOf(ax, ay + 1)
            }
        }
        for(i in 1..n) print("${a[i]} ")
        println()
    }
}