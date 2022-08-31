import kotlin.random.*

fun factorize(n: Int): MutableList<Int> {
    var ans = mutableListOf<Int>()
    var cur = n
    var i = 2
    while (i * i <= cur) {
        if (cur % i == 0) {
            ans.add(i)
            while (cur % i == 0) {
                cur /= i
            }
        }
        i += 1
    }
    if (cur > 1) {
        ans.add(cur)
    }
    return ans
}

fun ask(h: Int, w: Int, n: Int, m: Int): Boolean {
    if (h < n) {
        if (2 * h < n) {
            println("? $h $w 1 1 ${h + 1} 1")
        } else {
            println("? ${n - h} $w 1 1 ${h + 1} 1")
        }
    } else {
        if (2 * w < m) {
            println("? $h $w 1 1 1 ${w + 1}")
        } else {
            println("? $h ${m - w} 1 1 1 ${w + 1}")
        }
    }
    return readLine()!!.toInt() == 1
}

fun check(cnt: Int, h: Int, w: Int, n: Int, m: Int): Boolean {
    if (h < n) {
        var cur = 1
        while (2 * cur <= cnt) {
            if (!ask(cur * h, w, n, m)) {
                return false
            }
            cur *= 2
        }
        if (cur < cnt) {
            return ask(cur * h, w, n, m)
        } else {
            return true
        }
    } else {
        var cur = 1
        while (2 * cur <= cnt) {
            if (!ask(h, cur * w, n, m)) {
                return false
            }
            cur *= 2
        }
        if (cur < cnt) {
            return ask(h, cur * w, n, m)
        } else {
            return true
        }
    }
}

fun cnt_divs(n: Int): Int {
    var res = 0
    for (i in 1..n) {
        if (n % i == 0) {
            res += 1
        }
    }
    return res
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var ans = 1

    var p = n
    var ps = factorize(n)
    for (q in ps) {
        while (p % q == 0 && check(q, p / q, m, n, m)) {
            p /= q
        }
    }
    ans *= cnt_divs(n / p)

    p = m
    ps = factorize(m)
    for (q in ps) {
        while (p % q == 0 && check(q, n, p / q, n, m)) {
            p /= q
        }
    }
    ans *= cnt_divs(m / p)

    println("! $ans")
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}