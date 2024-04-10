import java.io.BufferedReader
import kotlin.system.exitProcess

fun main() {
    fun modPow(n: Long, k: Int, m: Long): Long {
        if (k == 0) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1) {
            half %= m
            half *= n
        }
        return half % m
    }

    val mod = 1_000_000_007
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val halfN = n shr 1
    val factorials = LongArray(halfN + 1)
    factorials[0] = 1L
    for (x in 1..halfN) {
        factorials[x] = (x * factorials[x - 1]) % mod
    }
    val invFactorials = LongArray(halfN + 1)
    invFactorials[halfN] = modPow(factorials[halfN], mod - 2, mod.toLong())
    for (x in halfN downTo 1) {
        invFactorials[x - 1] = (x * invFactorials[x]) % mod
    }
    fun choose(nC: Int, kC: Int): Long {
        val ret = (factorials[nC] * invFactorials[kC]) % mod
        return (ret * invFactorials[nC - kC]) % mod
    }

    val nums = if (n == 1) {
        println(br.readInt())
        exitProcess(0)
    } else if (n and 1 == 0) {
        IntArray(n) {
            br.readInt()
        }
    } else {
        val initial = IntArray(n) { br.readInt() }
        IntArray(n - 1) { idx ->
            if (idx and 1 == 0) {
                (initial[idx] + initial[idx + 1]) % mod
            } else {
                (initial[idx] + mod - initial[idx + 1]) % mod
            }
        }
    }
    val newN = (nums.size shr 1) - 1
    var sumA = 0L
    var sumB = 0L
    for (x in nums.indices) {
        val k = x shr 1
        if (x and 1 == 0) {
            sumA += nums[x] * choose(newN, k)
            sumA %= mod
        } else {
            sumB += nums[x] * choose(newN, k)
            sumB %= mod
        }
    }
    if (newN and 1 == 0) {
        println((sumA + sumB) % mod)
    } else {
        println((sumA - sumB + mod) % mod)
    }
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