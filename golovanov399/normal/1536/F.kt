import java.util.*
import kotlin.math.*

const val mod = 1_000_000_007

fun solve() {
    val n = readLine()!!.toInt()
    val inv = LongArray(n + 1) { 1L }
    val fact = LongArray(n + 1) { 1L }
    val invfact = LongArray(n + 1) { 1L }
    for (i in 2..n) {
        inv[i] = mod - inv[mod % i] * (mod / i) % mod
        fact[i] = fact[i - 1] * i % mod
        invfact[i] = invfact[i - 1] * inv[i] % mod
    }

    fun choose(n: Int, k: Int): Long = fact[n] * invfact[k] % mod * invfact[n - k] % mod
    var ans = 0L
    if (n % 2 == 0) {
        ans += 2 * fact[n]
    }
    for (k in (2 - n%2)..(n/2) step 2) {
        ans += (choose(n - k, k) + choose(n - 1 - k, k - 1)) * 2 % mod * fact[n - k] % mod
    }
    println(ans % mod)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}