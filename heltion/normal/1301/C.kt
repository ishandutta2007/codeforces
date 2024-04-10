fun main(){
    fun readInt() = readLine()!!.toInt()
    repeat(readInt()){
        val (n, m) = readLine()!!.split(' ').map(String::toLong)
        val x = (n - m) / (m + 1)
        val y = (n - m) % (m + 1)
        println(n * (n + 1) / 2 - y * ((x + 1) * (x + 2) / 2) - (m + 1 - y)  * (x * (x + 1) / 2))
    }
}