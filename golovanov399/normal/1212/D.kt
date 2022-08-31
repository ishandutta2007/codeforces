fun ord(x: Long, y: Int): Int {
    return if (x % y > 0) 0 else ord(x / y, y) + 1
}

fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toLong).toMutableList()
    a.sortWith(compareBy({-ord(it, 3)}, {ord(it, 2)}))
    println(a.joinToString(prefix = "", postfix = "", separator = " "))
}