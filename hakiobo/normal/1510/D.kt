import java.io.BufferedReader
import kotlin.math.min


fun main() {
    fun modPow(n: Int, k: Int, m: Int): Int {
        if (k == 0) {
            return 1
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1 == 1) {
            half %= m
            half *= n
        }
        return half % m
    }


    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val d = br.readInt()
    val nums = List<Int>(n) { br.readInt() }.sorted()
    val buckets = List(10) { mutableListOf<Int>() }

    for (num in nums) {
        buckets[num % 10] += num
    }
    if (d == 5) {
        val numToUse = IntArray(10)
        val ans = mutableListOf<Int>()
        var digit = 1
        for (bucket in buckets.indices) {
            if (bucket and 1 == 0) continue
            for (num in buckets[bucket]) {
                ans += num
            }
            numToUse[bucket] = buckets[bucket].size
            digit *= modPow(bucket, buckets[bucket].size, 10)
            digit %= 10
        }
        if (digit == 5) {
            println(numToUse.sum())
            println(ans.joinToString(" "))
        } else {
            print(-1)
        }
    } else if (d and 1 == 1) {
        val numToUse = IntArray(10)
        var digit = 1
        var totalNums = 0
        for (bucket in buckets.indices) {
            if (bucket and 1 == 0) continue
            if (bucket == 5) continue
            totalNums += buckets[bucket].size
            numToUse[bucket] = buckets[bucket].size
            digit *= modPow(bucket, buckets[bucket].size, 10)
            digit %= 10
        }

        var best = Long.MAX_VALUE
        for (three in 0..min(3, buckets[3].size)) {
            for (nine in 0..min(1, buckets[9].size)) {
                var check = 1L
                for (num in buckets[3].take(three)) {
                    check *= num
                }
                for (num in buckets[9].take(nine)) {
                    check *= num
                }
                if (((check * d) % 10).toInt() == digit && check < best && three + nine < totalNums) {
                    best = check
                    numToUse[3] = buckets[3].size - three
                    numToUse[7] = buckets[7].size
                    numToUse[9] = buckets[9].size - nine
                }
            }
        }
        for (seven in 0..min(3, buckets[7].size)) {
            for (nine in 0..min(1, buckets[9].size)) {
                var check = 1L
                for (num in buckets[7].take(seven)) {
                    check *= num
                }
                for (num in buckets[9].take(nine)) {
                    check *= num
                }
                if (((check * d) % 10).toInt() == digit && check < best && seven + nine < totalNums) {
                    best = check
                    numToUse[3] = buckets[3].size
                    numToUse[7] = buckets[7].size - seven
                    numToUse[9] = buckets[9].size - nine
                }
            }
        }
        if (best == Long.MAX_VALUE) {
            print(-1)
        } else {
            println(numToUse.sum())
            val ans = mutableListOf<Int>()
            for (bucket in 0..9) {
                ans += buckets[bucket].takeLast(numToUse[bucket])
            }
            println(ans.joinToString(" "))
        }
    } else if (d == 0) {
        val numToUse = IntArray(10)
        val ans = mutableListOf<Int>()
        var digit = 1
        for (bucket in buckets.indices) {
            for (num in buckets[bucket]) {
                ans += num
            }
            numToUse[bucket] = buckets[bucket].size
            digit *= modPow(bucket, buckets[bucket].size, 10)
            digit %= 10
        }
        if (digit == 0) {
            println(numToUse.sum())
            println(ans.joinToString(" "))
        } else {
            print(-1)
        }
    } else {
        val numToUse = IntArray(10)
        var digit = 1
        var evenCount = 0
        for (bucket in buckets.indices) {
            if (bucket % 5 == 0) continue
            if (bucket and 1 == 0) evenCount += buckets[bucket].size
            numToUse[bucket] = buckets[bucket].size
            digit *= modPow(bucket, buckets[bucket].size, 10)
            digit %= 10
        }

        var best = Long.MAX_VALUE
        for (threeMod5 in 0..min(3, buckets[3].size + buckets[8].size)) {
            for (fourMod5 in 0..min(1, buckets[4].size + buckets[9].size)) {
                for (three in 0..threeMod5) {
                    val eight = threeMod5 - three
                    if (eight > buckets[8].size || three > buckets[3].size) continue
                    for (nine in 0..fourMod5) {
                        val four = fourMod5 - nine
                        if (nine > buckets[9].size || four > buckets[4].size) continue
                        val evenUsed = four + eight
                        var check = 1L
                        for (num in buckets[3].take(three)) {
                            check *= num
                        }
                        for (num in buckets[4].take(four)) {
                            check *= num
                        }
                        for (num in buckets[8].take(eight)) {
                            check *= num
                        }
                        for (num in buckets[9].take(nine)) {
                            check *= num
                        }
                        if (((check * d) % 5).toInt() == digit % 5 && check < best && evenUsed < evenCount) {
                            best = check
                            numToUse[2] = buckets[2].size
                            numToUse[3] = buckets[3].size - three
                            numToUse[4] = buckets[4].size - four
                            numToUse[7] = buckets[7].size
                            numToUse[8] = buckets[8].size - eight
                            numToUse[9] = buckets[9].size - nine
                        }
                    }
                }
            }
        }

        for (twoMod5 in 0..min(3, buckets[2].size + buckets[7].size)) {
            for (fourMod5 in 0..min(1, buckets[4].size + buckets[9].size)) {
                for (seven in 0..twoMod5) {
                    val two = twoMod5 - seven
                    if (two > buckets[2].size || seven > buckets[7].size) continue
                    for (nine in 0..fourMod5) {
                        val four = fourMod5 - nine
                        if (nine > buckets[9].size || four > buckets[4].size) continue
                        val evenUsed = four + two
                        var check = 1L
                        for (num in buckets[2].take(two)) {
                            check *= num
                        }
                        for (num in buckets[4].take(four)) {
                            check *= num
                        }
                        for (num in buckets[7].take(seven)) {
                            check *= num
                        }
                        for (num in buckets[9].take(nine)) {
                            check *= num
                        }
                        if (((check * d) % 5).toInt() == digit % 5 && check < best && evenUsed < evenCount) {
                            best = check
                            numToUse[2] = buckets[2].size - two
                            numToUse[3] = buckets[3].size
                            numToUse[4] = buckets[4].size - four
                            numToUse[7] = buckets[7].size - seven
                            numToUse[8] = buckets[8].size
                            numToUse[9] = buckets[9].size - nine
                        }
                    }
                }
            }
        }
        if (best == Long.MAX_VALUE) {
            print(-1)
        } else {
            println(numToUse.sum())
            val ans = mutableListOf<Int>()
            for (bucket in 0..9) {
                ans += buckets[bucket].takeLast(numToUse[bucket])
            }
            println(ans.joinToString(" "))
        }
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