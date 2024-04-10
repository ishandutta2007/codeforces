fun main(){
    repeat(readLine()!!.toInt()){
        val (a, b) = readLine()!!.split(' ').map(String::toInt)
        println(maxOf(minOf(a, b) * 2, a, b) * maxOf(minOf(a, b) * 2, a, b))
    }
}