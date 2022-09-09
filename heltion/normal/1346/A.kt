fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val (n, k) = readInts()
        val n1 = n / (1 + k + k * k + k * k * k)
        println("$n1 ${n1 * k} ${n1 * k * k} ${n1 * k * k * k}")
    }
}