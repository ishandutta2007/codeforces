import kotlin.math.*

fun solve() {
    val (n, m, k) = readLine()!!.split(' ').map(String::toInt)
    if (n % m == 0) {
        repeat(k) {
            for (i in 0 until n step n / m) {
                print("${n / m} ")
                println(((i+1)..(i+n/m)).joinToString(" "))
            }
        }
        return
    }
    val big = n / m + 1
    val cntBig = n % m
    var from = 0
    fun output(cnt: Int) {
        print("$cnt ")
        println((0 until cnt).map {
            from += 1
            val res = from
            if (from == n) {
                from = 0
            }
            res
        }.joinToString(" "))
    }
    repeat(k) {
        repeat(cntBig) {
            output(big)
        }
        val huerm = from
        repeat(m - cntBig) {
            output(big - 1)
        }
        from = huerm
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}