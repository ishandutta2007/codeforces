fun solve(a: Int, x: Int, y: Int): Int {
    if (x < 0 || x > a || y < 0 || y > a) {
        return 2
    } else if (x == 0 || x == a || y == 0 || y == a) {
        return 1
    } else {
        return 0
    }
}

fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    println(solve(a, x, y))
}