import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var mx = 0
    var idx = 0
    for (i in 0 until n) {
        if (a[i] >= mx) {
            mx = a[i]
            idx = i
        }
    }
    println(n.toLong() * (mx - 1) + idx + 1)
}