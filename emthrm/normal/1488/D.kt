import kotlin.math.*

fun main(args: Array<String>) {
    var t = readLine()!!.toInt()
    repeat(t) {
        var (n, s) = readLine()!!.split(" ").map{ it.toLong() }
        var lb = (s + n - 1) / n
        var ub = s - (n - 1) + 1
        while (ub - lb > 1) {
            var mid = (lb + ub) / 2
            var problem = mid
            var a = mid
            for (day in n - 1 downTo 1) {
                a = (a + 1) / 2
                if (a == 1L) {
                    problem += day
                    break
                }
                problem += a
                if (problem > s) break
            }
            if (problem <= s) {
                lb = mid
            } else {
                ub = mid
            }
        }
        println(lb)
    }
}