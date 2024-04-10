fun main(){
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    print((a.max()!! - 1).toLong() * n + a.lastIndexOf(a.max()!!) + 1)
}