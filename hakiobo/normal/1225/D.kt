import java.io.BufferedReader

private const val TEN_TENTH = 10_000_000_000L
private const val TEN_FIFTH = 100_000

fun main() {
    val sieve = IntArray(TEN_FIFTH + 1)
    for (i in 2..TEN_FIFTH) {
        if (sieve[i] == 0) {
            for (j in i..TEN_FIFTH step i) {
                sieve[j] = i
            }
        }
    }
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val k = br.readInt()

    val counts = LongArray(TEN_FIFTH + 1)
    repeat(n) {
        counts[br.readInt()]++
    }
    var base = 2L
    var overflowed = false
    var ans = (counts[1] * (counts[1] - 1)) shr 1
    while (!overflowed) {
        var cur = 1L
        for (i in 0 until k) {
            cur *= base
            if (cur > TEN_TENTH) break
        }
        if (cur <= TEN_TENTH) {
            val factors = mutableListOf(1L)
            fun addFactor(num: Long) {
                factors += num
                val other = cur / num
                if (num in (other + 1)..TEN_FIFTH) {
                    ans += counts[num.toInt()] * counts[other.toInt()]
                } else if (num == other) {
                    ans += (counts[num.toInt()] * (counts[num.toInt()] - 1)) shr 1
                }
            }

            var cBase = base.toInt()
            while (cBase != 1) {
                val p = sieve[cBase]
                var ct = 0
                while (cBase % p == 0) {
                    cBase /= p
                    ct += k
                }
                val initSize = factors.size
                var curP = 1L
                repeat(ct) {
                    curP *= p
                    for (i in 0 until initSize) {
                        addFactor(curP * factors[i])
                    }
                }
            }
            base++
        } else {
            overflowed = true
        }
    }
    println(ans)
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