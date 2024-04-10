
import java.lang.System.`in`
import kotlin.system.exitProcess

private val factorials = MutableList(2) {
    1L
}

private const val MOD = 998244353


fun main() {
    val (n, m) = `in`.bufferedReader().readLine().split(' ').map(String::toInt)
    if (n == 2) {
        print(0)
        exitProcess(0)
    }
    var ways = factorial(m) * (n - 2)
    ways %= MOD
    ways *= modInverse(factorial(n - 1))
    ways %= MOD
    ways *= modInverse(factorial(m - n + 1))
    ways %= MOD
    ways *= modPow(2L, n - 3)
    ways %= MOD
    print(ways)

}

private fun modInverse(num: Long): Long {
    return modPow(num, MOD - 2)
}

private fun modPow(base: Long, pow: Int): Long {
    if (pow == 0) {
        return 1L
    }
    var halfPow = modPow(base, pow / 2)
    halfPow *= halfPow
    halfPow %= MOD
    if (pow and 1 == 1) {
        halfPow *= base
        halfPow %= MOD
    }
    return halfPow
}

private fun factorial(n: Int): Long {
    if (n > factorials.size) {
        for (i in factorials.size until n) {
            factorial(i)
        }
    }
    if (n == factorials.size) {
        var newFact = n * factorials[n - 1]
        newFact %= MOD
        factorials += newFact
    }
    return factorials[n]
}