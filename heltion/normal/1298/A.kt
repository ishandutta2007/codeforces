fun main(){
    val x = readLine()!!.split(' ').map{it.toInt()}.sorted()
    for(i in 0 until 3) println(x[3] - x[i])
}