import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        val n = readLine()!!.toInt()
        var mini = 0
        var maxi = Int.MAX_VALUE
        repeat (n) {
            val (s, t, r) = readLine()!!.split(' ')
            val commonSuffixLength = s.commonSuffixWith(t).length
            if (r == "1") {
                maxi = min(maxi, commonSuffixLength)
            } else {
                mini = max(mini, commonSuffixLength + 1)
            }
        }
        val ans = (mini..maxi).toList()
        println(ans.size)
        println(ans.joinToString(" "))
    }
}