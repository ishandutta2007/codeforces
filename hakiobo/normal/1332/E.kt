private const val MOD = 998_244_353
fun main() {
    val (rows, cols, lower, upper) = System.`in`.bufferedReader().readLine().split(' ').map(String::toLong)
    val dif = upper - lower + 1
    val pow = (rows * cols)
    var ans = modPow(dif, pow)
    if (rows * cols and 1L == 0L) {
        if (dif and 1L == 1L) {
            ans++
        }
        if(ans and 1L == 1L){
            ans += MOD
        }
        ans = ans shr 1
    }
    print(ans%MOD)
}

private fun modPow(base: Long, pow: Long): Long {
    if (pow == 0L) {
        return 1L
    }
    var half = modPow(base, pow shr 1)
    half *= half
    half %= MOD
    if (pow and 1L == 1L) {
        half *= base
        half %= MOD
    }
    return half
}