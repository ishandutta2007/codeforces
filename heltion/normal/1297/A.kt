fun main(){
    fun readInt() = readLine()!!.toInt()
    repeat(readInt()){
        val n = readInt()
        when{
            n <= 999 -> println(n)
            n < 999500 -> println("${(n + 500) / 1000}K")
            else -> println("${(n + 500000) / 1000000}M")
        }
    }
}