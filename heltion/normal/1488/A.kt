fun main(){
    repeat(readLine()!!.toInt()){
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }
        println((y / x).toString().map { it.toChar() - '0' }.sum() + y % x)
    }
}