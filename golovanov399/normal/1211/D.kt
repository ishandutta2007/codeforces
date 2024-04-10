import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    val (n, a, b, k) = readLine()!!.split(' ').map(String::toInt)
    val ratings = readLine()!!.split(' ').map(String::toInt).sorted()
    var ans = 0
    var used = BooleanArray(n) {false}
    if (a > b) {
        var j = 0
        var i = 0
        while (i < n) {
            if (used[i]) {
                i += 1
                continue
            }
            while (j < n && ratings[j] < ratings[i] * k) {
                j += 1
            }
            if (i + a - 1 < n && j + b - 1 < n && ratings[i + a - 1] == ratings[i] && ratings[j + b - 1] == ratings[j] && ratings[j] == ratings[i] * k) {
                ans += 1
                for (k in 0 until b) {
                    used[j] = true
                    j += 1
                }
                i += a
            } else {
                i += 1
            }
        }
    } else {
        var j = n - 1
        var i = n - 1
        while (i >= 0) {
            if (used[i]) {
                i -= 1
                continue
            }
            while (j >= 0 && ratings[j] * k > ratings[i]) {
                j -= 1
            }
            if (i - b + 1 >= 0 && j - a + 1 >= 0 && ratings[i - b + 1] == ratings[i] && ratings[j - a + 1] == ratings[j] && ratings[j] * k == ratings[i]) {
                ans += 1
                for (k in 0 until a) {
                    used[j] = true
                    j -= 1
                }
                i -= b
            } else {
                i -= 1
            }
        }
    }
    println(ans)
}