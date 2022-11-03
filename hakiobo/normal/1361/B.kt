import java.io.BufferedReader

private const val MOD = 1_000_000_007

fun main() {
    fun modPow(base: Long, pow: Int): Long {
        if (pow == 0) {
            return 1L
        }
        var half = modPow(base, pow shr 1)
        half *= half
        if (pow and 1 == 1) {
            half %= MOD
            half *= base
        }
        return half % MOD
    }

    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val n = br.readInt()
        val p = br.readInt().toLong()
        val nums = IntArray(n) {
            br.readInt()
        }.sortedArrayDescending()

        if (p == 1L) {
            sb.append(n and 1).append('\n')
        } else {
            val a = mutableListOf<Pair<Int, Int>>()
            val b = mutableListOf<Pair<Int, Int>>()
            var equalUpTo = -1
            var lowerIsA = true

            for (num in nums) {
                val low = if (lowerIsA) a else b
                if (low.size > 0 && low.last().first == num) {
                    low[low.lastIndex] = Pair(num, low.last().second + 1)
                    if (equalUpTo == low.lastIndex) {
                        equalUpTo--
                    }
                } else {
                    low += Pair(num, 1)
                }
                while (low.last().second == p.toInt()) {
                    if (low.size >= 2 && low[low.lastIndex - 1].first == low.last().first + 1) {
                        low.removeAt(low.lastIndex)
                        low[low.lastIndex] = Pair(low.last().first, low.last().second + 1)
                    } else {
                        low[low.lastIndex] = Pair(low.last().first + 1, 1)
                        break
                    }
                    if (equalUpTo == low.lastIndex) {
                        equalUpTo--
                    }
                }
                while (equalUpTo < a.lastIndex && equalUpTo < b.lastIndex) {
                    val aVal = a[equalUpTo + 1]
                    val bVal = b[equalUpTo + 1]
                    if (aVal.first != bVal.first) {
                        lowerIsA = aVal.first < bVal.first
                        break
                    } else if (aVal.second != bVal.second) {
                        lowerIsA = aVal.second < bVal.second
                        break
                    }
                    equalUpTo++
                }
                if (equalUpTo == a.lastIndex) {
                    lowerIsA = true
                } else if (equalUpTo == b.lastIndex) {
                    lowerIsA = false
                }
            }
            var sumA = 0L
            var sumB = 0L
            for (entry in a) {
                val pow = entry.first
                sumA += entry.second * modPow(p, pow)
                sumA %= MOD
            }
            for (entry in b) {
                val pow = entry.first
                sumB += entry.second * modPow(p, pow)
                sumB %= MOD
            }
            val dif = if (lowerIsA) {
                (sumB - sumA + MOD + MOD) % MOD
            } else {
                (sumA - sumB + MOD + MOD) % MOD
            }
            sb.append(dif).append('\n')
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()

@Suppress("DuplicatedCode")
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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}