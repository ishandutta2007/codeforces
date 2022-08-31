import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt).toMutableList()
    var M = mutableMapOf<Int, Int>()
    for (i in 0 until a.size) {
        M[a[i]] = i
    }
    val b = a.filterIndexed {x, y -> M[y] == x}
    println(b.size)
    println(b.joinToString(separator = " "))
}