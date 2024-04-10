import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    if (n == 3) {
        println("3 2 1")
        println("1 3 2")
        println("3 1 2")
    } else if (n == 4) {
        println("4 1 3 2")
        println("1 2 4 3")
        println("3 4 1 2")
        println("2 4 1 3")
    } else {
        val rem = (n + 1) / 2
        val a = MutableList(rem) { it + 1 }
        val ans = MutableList(n) { 0 }
        for (i in 1 until n step 2) {
            ans[i] = n - i / 2
        }
        repeat (n) {
            for (i in 0 until a.size) {
                ans[i * 2] = a[i]
            }
            println(ans.joinToString(" "))
            var i = a.size - 1
            while (i > 0 && a[i] < a[i - 1]) {
                --i
            }
            if (i == 0) {
                return
            }
            i -= 1
            var j = i + 1
            while (j + 1 < a.size && a[j + 1] > a[i]) {
                j += 1
            }
            a[i] = a[j].also { a[j] = a[i] }
            var (l, r) = i to a.size
            while (r > l + 2) {
                l += 1
                r -= 1
                a[l] = a[r].also { a[r] = a[l] }
            }
        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}