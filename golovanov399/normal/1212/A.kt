fun subtract_one(x: Int): Int {
    return if (x % 10 == 0) x / 10 else x - 1
}

fun main() {
    var (x, k) = readLine()!!.split(' ').map(String::toInt)
    for (i in 0 until k) {
        x = subtract_one(x)
    }
    println(x)
}