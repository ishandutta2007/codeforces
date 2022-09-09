fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    val mod = 998244353L
    val (n, k) = readInts()
    val f = LongArray(n + 1)
    val g = LongArray(n + 1)
    for(i in 0..n) f[i] = if(i == 0) 1 else f[i - 1] * i % mod
    for(i in 1..n) g[i] = if(i == 1) 1 else (mod - mod / i) * g[mod.toInt() % i] % mod
    for(i in 0..n) g[i] = if(i == 0) 1 else g[i] * g[i - 1] % mod
    var ans = 0L
    val C = {
        m : Int, n : Int ->
        if(m < n) 0L
        else f[m] * g[n] % mod * g[m - n] % mod
    }
    for(i in 1..n)
        ans += C(n / i - 1, k - 1)
    print(ans % mod)
}