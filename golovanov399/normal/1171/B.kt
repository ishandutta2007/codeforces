fun main() {
    val (y, b, r) = readLine()!!.split(' ').map(String::toInt)
    println(3 * minOf(y + 1, b, r - 1))
}