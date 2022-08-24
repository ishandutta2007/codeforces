import kotlin.math.*
import kotlin.system.exitProcess

fun main() {
    val (n, w) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).reversed().toIntArray()

    var l = 0
    var r = w

    for (d in a) {
        l -= d
        r -= d
        l = max(l, 0)
        r = min(r, w)

        if (r < 0 || l > w) {
            println(0)
            exitProcess(0)
        }
    }
    println(r - l + 1)
}