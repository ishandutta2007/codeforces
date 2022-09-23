fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if(x < a && y < a && x > 0 && y > 0)
        println(0)
    else if(x <= a && y <= a && x >= 0 && y >= 0)
        println(1)
    else
        println(2)
}