import kotlin.math.*

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val mod = 998244353
    var invs = LongArray(k + 1) {1}
    for (i in 2..k) {
        invs[i] = mod - invs[mod % i] * (mod / i) % mod
    }
    var ans = 0L
    for (mn in 1..n) {
        val cn = n / mn - 1
        val ck = k - 1
        if (cn < ck) {
            continue
        }
        var tmp = 1L
        for (i in 0 until ck) {
            tmp = tmp * (cn - i) % mod
        }
        ans += tmp
    }
    ans %= mod
    for (i in 1 until k) {
        ans = ans * invs[i] % mod
    }
    println(ans)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}