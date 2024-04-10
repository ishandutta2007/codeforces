import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun gcd(x: Int, y: Int): Int {
    return if (y == 0) x else gcd(y, x % y)
}

fun solve() {
    val (k, n) = readLine()!!.split(' ').map(String::toInt)
    val ps = readLine()!!.split(' ').map(String::toInt)
    val xs = readLine()!!.split(' ').map(String::toInt)

    if (n <= 2) {
        println("YES")
        println("${xs[0]} ${ps[0]}")
        println("${xs[1]} ${ps[0]}")
        return
    }

    val N = 1111111
    var which = IntArray(N) { 0 }
    for (p in ps.reversed()) {
        for (i in 0 until N step p) {
            which[i] = p
        }
    }


    for (i in 0..2) {
        for (j in 0 until i) {
            for (p in ps) {
                if (which[p] != p) {
                    continue
                }
                if ((xs[i] - xs[j]) % p > 0) {
                    continue
                }
                var remaining = mutableListOf<Int>()
                for (x in xs) {
                    if (x % p != xs[j] % p) {
                        remaining.add(x)
                    }
                }
                var g = 0
                if (remaining.size > 1) {
                    for (t in 1 until remaining.size) {
                        g = gcd(g, remaining[t] - remaining[0])
                    }
                }
                if (which[g] > 0) {
                    println("YES")
                    println("${xs[j]} $p")
                    println("${if (remaining.size > 0) remaining[0] else 1} ${which[g]}")
                    return
                }
            }
        }
    }
    println("NO")
}

fun main() {
    val t = 1 // readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}