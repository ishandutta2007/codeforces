import kotlin.math.min

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        val n = readLine()!!.toInt()
        val (a, v_a) = readLine()!!.split(' ').map { it.toInt() }
        val (c, v_c) = readLine()!!.split(' ').map { it.toInt() }
        val b = readLine()!!.toInt()
        println(min(v_a + b - a, v_c))
    }
}