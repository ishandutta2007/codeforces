import kotlin.math.*
import kotlin.system.exitProcess

const val N = 1_000_000
val erat = IntArray(N) { 0 }
val primes = mutableListOf<Int>()

fun f(n: Int): Int {
    var res = 0
    var x = n
    for (p in primes) {
        if (x < N || p > x / p) {
            break
        }
        while (x % p == 0) {
            x /= p
            res += 1
        }
    }
    if (x < N) {
        while (x > 1) {
            res += 1
            x /= erat[x]
        }
    } else {
        res += 1
    }
    return res
}

fun solve() {
    val (a, b, k) = readLine()!!.split(' ').map(String::toInt)
    if (k == 1) {
        if (a == b) {
            println("No")
        } else {
            println(if (a % b == 0 || b % a == 0) "Yes" else "No")
        }
        return
    }
    println(if (f(a) + f(b) >= k) "Yes" else "No")
}

fun main() {
    erat[1] = 1
    for (i in 2 until N) {
        if (erat[i] == 0) {
            erat[i] = i
            primes.add(i)
        }
        for (p in primes) {
            if (p > erat[i] || i * p >= N) {
                break
            }
            erat[i * p] = p
        }
    }

    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}