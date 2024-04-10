import kotlin.math.*

fun solve() {
    val (h, m) = readLine()!!.split(' ').map(String::toInt)
    var (x, y) = readLine()!!.split(':').map(String::toInt)
    val reflect_digit = listOf(0, 1, 5, -1, -1, 2, -1, -1, 8, -1)
    fun is_correct(x: Int, y: Int): Boolean {
        if (reflect_digit[x % 10] == -1 || reflect_digit[x / 10] == -1 || reflect_digit[y % 10] == -1 || reflect_digit[y / 10] == -1) {
            return false
        }
        val nx = reflect_digit[y % 10] * 10 + reflect_digit[y / 10]
        val ny = reflect_digit[x % 10] * 10 + reflect_digit[x / 10]
        return nx in 0 until h && ny in 0 until m
    }
    while (!is_correct(x, y)) {
        y += 1
        if (y == m) {
            y = 0
            x += 1
            if (x == h) {
                x = 0
            }
        }
    }
    println("${x.toString().padStart(2, '0')}:${y.toString().padStart(2, '0')}")
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}