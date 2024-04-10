fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val (n, m, k) = readInts()
        val x = minOf(m, n / k)
        val y = (m - x + k - 2) / (k - 1)
        println(x - y)
    }
}