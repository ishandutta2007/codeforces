fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    var ans: Int = 2
    if( 0 < x && x < a && 0 < y && y < a ) ans = 0
    else if( ( ( x == 0 || x == a ) && ( 0 <= y && y <= a ) ) ||
             ( ( y == 0 || y == a ) && ( 0 <= x && x <= a ) ) ) ans = 1
    println( ans )
}