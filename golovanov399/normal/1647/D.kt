import kotlin.math.*

fun factorize(n: Int): List<Int> {
    var nn = n
    val res = mutableListOf<Int>()
    var i = 2
    while (i * i <= nn) {
        while (nn % i == 0) {
            res.add(i)
            nn /= i
        }
        i += 1
    }
    if (nn > 1) {
        res.add(nn)
    }
    return res
}

fun solve() {
    val (x, d) = readLine()!!.split(' ').map(String::toInt)
    if (x / d % d > 0) {
        println("No")
        return
    }
    val ps = factorize(d)

    if (ps.all { it == ps[0] }) {
        val p = ps[0]
        var cnt = 0
        var y = x
        while (y % p == 0) {
            cnt += 1
            y /= p
        }

        val cntIfSmall = cnt / ps.size
        if ((cntIfSmall - 1) * (2 * ps.size - 1) >= cnt || factorize(y).size + cnt % ps.size >= 2) {
            println("Yes")
        } else {
            println("No")
        }
        return
    }

    when {
        x / d / d % d == 0 -> {
            println("Yes")
        }
        factorize(x / d / d).size >= 2 -> {
            println("Yes")
        }
        else -> {
            println("No")
        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}