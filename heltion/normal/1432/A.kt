fun main(){
    repeat(readLine()!!.toInt()){
        val (A, B) = readLine()!!.split(' ').map(String::toInt)
        println(A + B)
    }
}