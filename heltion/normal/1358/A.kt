fun main(){
    repeat(readLine()!!.toInt()){
        val (n, m) = readLine()!!.split(' ').map(String::toInt)
        println((n * m + 1) / 2)
    }
}