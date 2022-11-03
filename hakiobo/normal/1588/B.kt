import kotlin.system.exitProcess

fun main() {
    val t = readLine()!!.toInt()

    fun query(low: Int, high: Int): Long {
        println("? ${low + 1} ${high + 1}")
        val ans = readLine()!!.toLong()
        if (ans == -1L) exitProcess(0)
        return ans
    }

    fun findK(x: Long, n: Long): Int {
        var low = 1L
        var high = n
        while (low < high) {
            val mid = (low + high) shr 1
            val check = (mid * (mid - 1)) shr 1
            if (check == x) return mid.toInt()
            if (check < x) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        val check = (low * (low - 1)) shr 1
        if (check == x) return low.toInt()
        exitProcess(-5)
    }
    repeat(t) {
        val n = readLine()!!.toInt()
        var high = n - 1
        var low = 0
        val tot = query(low, high)
        var done = false
        var foundLow = false
        while (!foundLow && !done) {
            val mid = (high + low) shr 1
            when (val check = query(low, mid)) {
                0L -> low = mid
                tot -> high = mid
                else -> {
                    val check2 = query(low, mid + 1)
                    val dif = check2 - check
                    val dif2 = (dif * (dif - 1)) shr 1
                    if (dif2 == check) {
                        low = (mid - dif + 1).toInt()
                        foundLow = true
                    } else {
                        val a = check - dif2
                        val b = tot - a
                        val ak = findK(a, n.toLong())
                        val bk = findK(b, n.toLong())
                        high = (mid + bk - dif).toInt()
                        low = high - ak - bk + 1
                        println("! ${low + 1} ${low + ak + 1} ${high + 1}")
                        done = true
                    }
                }
            }
        }
        if (!done) {
            val trueLow = low
            while (low < high) {
                val mid = (low + high) shr 1
                val q = query(trueLow, mid)
                if (q == tot) {
                    high = mid
                } else {
                    low = mid + 1
                }
            }
            val q = query(trueLow, high - 1)
            val dif = tot - q
            println("! ${trueLow + 1} ${high - dif + 1} ${high + 1}")
        }
    }
}