import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun isPrime(n: Int): Boolean {
    if (n == 1) {
        return false
    }
    var i = 2
    while (i * i <= n) {
        if (n % i == 0) {
            return false
        }
        i += 1
    }
    return true
}

fun solve() {
    val big = 1e18.toLong()
    var cur = 1L
    var qrs = mutableListOf<Long>()
    var primes = mutableListOf<Int>()
    for (i in 1..650) {
        if (isPrime(i)) {
            primes.add(i)
            if (cur <= big / i) {
                cur *= i
            } else {
                qrs.add(cur)
                cur = i.toLong()
            }
        }
    }
    if (cur > 1) {
        qrs.add(cur)
    }

    var active_primes = mutableListOf<Int>()
    for (q in qrs) {
        println("? $q")
        val g = readLine()!!.toInt()
        for (p in primes) {
            if (g % p == 0) {
                active_primes.add(p)
            }
        }
    }
    var ans = 1
    for (i in 0 until active_primes.size step 2) {
        var q = 1L
        var p = active_primes[i]
        while (q * p < 1e9) {
            q *= p
        }
        if (i + 1 < active_primes.size) {
            var qq = 1L
            p = active_primes[i + 1]
            while (qq * p < 1e9) {
                qq *= p
            }
            q *= qq
        }
        println("? $q")
        var g = readLine()!!.toInt()
        var tmp = 1
        p = active_primes[i]
        while (g % p == 0) {
            g /= p
            tmp += 1
        }
        ans *= tmp
        if (i + 1 < active_primes.size) {
            p = active_primes[i + 1]
            tmp = 1
            while (g % p == 0) {
                g /= p
                tmp += 1
            }
            ans *= tmp
        }
    }

    println("! ${ans + max(7, ans)}")
}

fun main() {
    val t = readLine()!!.toInt()

    for (i in 0 until t) {
        solve()
    }
}