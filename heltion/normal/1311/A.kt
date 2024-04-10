fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readIntArray() = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    repeat(readInt()){
        val (a, b) = readIntArray()
        println(when{
            a == b -> 0
            a % 2 == b % 2 -> if(a < b) 2 else 1
            else -> if(a < b) 1 else 2
        })
    }
}