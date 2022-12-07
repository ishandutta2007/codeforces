import java.io.BufferedReader

fun main() {
    val l = 31_621
    val sieve = IntArray(l + 1)
    val primes = run {
        val primes = mutableListOf<Int>()
        for (i in 2..l) {
            if (sieve[i] == 0) {
                sieve[i] = i
                primes.add(i)
                for (j in i * i..l step i) {
                    sieve[j] = i
                }
            }
        }
        primes.toIntArray()
    }
    val mod = 998_244_353L
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        var ans = 1L
        val nums = IntArray(n) { br.readInt() }
        for (i in 1 until n) {
            val curGcd = nums[i - 1]
            val nextGcd = nums[i]
            if (curGcd % nextGcd != 0) {
                ans = 0L
                break
            }
            var ratio = curGcd / nextGcd
            val baseChoices = m / nextGcd
            var choices = 0
            val myPrimes = mutableListOf<Int>()
            val myFactors = mutableListOf<Int>()
            val factorsPCt = mutableListOf<Int>()
            myFactors += 1
            factorsPCt += 0
            if (ratio > l) {
                for (p in primes) {
                    if (ratio % p == 0) {
                        myPrimes += p
                        ratio /= p
                        while (ratio % p == 0) ratio /= p
                        if (ratio <= l) break
                    }
                }
            }

            if (ratio <= l) {
                while (ratio != 1) {
                    val p = sieve[ratio]
                    myPrimes += p
                    while (ratio % p == 0) ratio /= p
                }
            } else {
                myPrimes += ratio
            }
            for (p in myPrimes) {
                val curL = myFactors.size
                for (j in 0 until curL) {
                    myFactors += p * myFactors[j]
                    factorsPCt += factorsPCt[j] + 1
                }
            }
            for (j in 0 until myFactors.size) {
                if (factorsPCt[j] and 1 == 0) {
                    choices += baseChoices / myFactors[j]
                } else {
                    choices -= baseChoices / myFactors[j]
                }
            }


            ans *= choices
            ans %= mod
        }
        bw.appendLine("$ans")
    }
    bw.flush()
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