import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    var a = readLine()!!.split(' ').map(String::toInt).toMutableList()
    a.sort()
    for (i in 0 until 3) {
        a[i] = a[3] - a[i]
    }
    println(a.subList(0, 3).joinToString(separator = " "))
}