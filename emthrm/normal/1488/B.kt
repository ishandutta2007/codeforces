import kotlin.math.min

fun main(args: Array<String>) {
    var t = readLine()!!.toInt()
    repeat(t) {
        var (n, k) = readLine()!!.split(" ").map{ it.toInt() }
        var s = readLine()!!
        var nest = 0
        var ans = 0
        s.forEach {
            if (it == '(') {
              ++nest
            } else {
              --nest
            }
            if (nest == 0) ++ans
        }
        println(min(ans + k, n / 2))
    }
}