import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val sieve = IntArray(31_624) { -1 }
    val primes = mutableListOf<Int>()
    for (i in 2 until sieve.size) {
        if (sieve[i] == -1) {
            primes += i
            sieve[i] = i
            var x = i * i
            while (x < sieve.size) {
                sieve[x] = i
                x += i
            }
        }
    }
    fun countPrimeFactors(n: Int): Int {
        var k = n
        var numFactors = 0
        for (prime in primes) {
            var numTimes = 0
            while (k % prime == 0) {
                k /= prime
                numTimes++
            }
            numFactors += numTimes
        }
        if (k != 1) numFactors++
        return numFactors
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val (a, b) = run {
            val a = br.readInt()
            val b = br.readInt()
            min(a, b) to max(a, b)
        }
        val k = br.readInt()

        val factorCount = countPrimeFactors(a) + countPrimeFactors(b)
        if (k == 1) {
            if (b % a == 0 && b != a) {
                sb.appendLine("YES")
            } else {
                sb.appendLine("NO")
            }
        } else if (k <= factorCount) {
            sb.appendLine("YES")
        } else {
            sb.appendLine("NO")
        }


    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}