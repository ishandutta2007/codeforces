fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}.reversed().distinct().reversed()
    println(a.size)
    for(i in a) print("$i ")
}