fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    var ok = 0
    if((x == 0) or (x == a) or (y == 0) or (y == a)) ok = 1
    if((x < 0) or (x > a) or (y < 0) or (y > a)) ok = 2
    println(ok)
}