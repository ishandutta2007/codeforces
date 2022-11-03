fun main() {
    fun modPow(n: Long, k: Long, m: Long): Long {
        if (k == 0L) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1L) {
            half %= m
            half *= n
        }
        return half % m
    }
    fun modInverse(n: Long, m: Long): Long{
        return modPow(n, m - 2, m)
    }
    val br = System.`in`.bufferedReader()
    val n = br.readLine()
    val mod = 1_000_000_007L
    var s = 0L
    var suffix = 0L
    var sufFactor = 1L
    var preFactor = 0L
    val inv10 = modInverse(10, mod)
    for(x in n.indices.reversed()){
        val digit = n[x] - '0'
        suffix += digit * sufFactor
        suffix %= mod
        sufFactor *= 10
        sufFactor %= mod

        preFactor *= 10
        preFactor += 1
        preFactor %= mod

        s += suffix * x
        s %= mod
    }
    var prefix = 0L
    for (x in n.indices){
        val digit = n[x] - '0'
        prefix *= 10L
        prefix += digit
        prefix %= mod

        preFactor += mod - 1
        preFactor *= inv10
        preFactor %= mod

        s += preFactor * prefix
        s %= mod
    }
    print(s)
}