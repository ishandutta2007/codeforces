private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

const val MOD = 998244353
data class Num (var v: Int = 0) {
    constructor (lv: Long) : this((lv % MOD).toInt()) { }
    init {
        v %= MOD
        if (v < 0) v += MOD
    }
    operator fun plus(o: Num): Num {
        return Num(v + o.v)
    }
    operator fun minus(o: Num): Num {
        return Num(v - o.v)
    }
    operator fun times(o: Num): Num {
        return Num(v.toLong() * o.v.toLong())
    }
}

fun go(): Num {
    val N = readInt()
    val S = MutableList<Pair<Int, Int>>(N, {
        val (x, y) = readInts()
        (2 * x) to (2 * y + 1)
    })

    var pts = (S.map({it.first}) + S.map({it.second})).sorted().distinct()
    val M = pts.size

    for (i in 0..S.size-1) {
        var (x, y) = S[i]
        x = pts.binarySearch(x)
        y = pts.binarySearch(y)
        assert(x >= 0)
        assert(y >= 0)
        S[i] = x to y
    }

    S.sortBy({it.first})

    val L = 1 shl 19
    val lazyMul = MutableList<Num>(2 * L, {Num(1)})
    val sumVal = MutableList<Num>(2 * L, {Num(0)})

    sumVal[L+0] = Num(1)
    for (i in L-1 downTo 1) {
        sumVal[i] = (sumVal[2*i] + sumVal[2 * i + 1]) * lazyMul[i]
    }

    fun updateNode(i: Int) {
        if (i == 0) {
            return
        }
        if (i < L) {
            sumVal[i] = (sumVal[2 * i] + sumVal[2 * i + 1]) * lazyMul[i]
        }
        updateNode(i / 2)
    }

    fun updateAll(i: Int) {
        updateNode(L + i)
    }

    fun propogateNode(i: Int) {
        if (i == 0) {
            return
        }
        propogateNode(i / 2)
        if (lazyMul[i] != Num(1)) {
            if (i < L) {
                sumVal[2 * i] *= lazyMul[i]
                lazyMul[2 * i] *= lazyMul[i]
                sumVal[2 * i + 1] *= lazyMul[i]
                lazyMul[2 * i + 1] *= lazyMul[i]
            }
            lazyMul[i] = Num(1)
        }
    }

    fun propogateAll(i: Int) {
        propogateNode(L + i)
    }

    var lastSeen = 0

    for ((x, y) in S) {
        if (x > lastSeen) {
            // we get to skip
            propogateAll(x)
            propogateAll(lastSeen)
            sumVal[L + x] = sumVal[L + lastSeen]
            sumVal[L + lastSeen] = Num(0)
            updateAll(x)
            updateAll(lastSeen)
        }

        // double [y, inf)
        propogateAll(y)
        propogateAll(L-1)
        var l = L + y
        var r = L + L
        while (l < r) {
            if (l % 2 != 0) {
                lazyMul[l] *= Num(2)
                sumVal[l] *= Num(2)
                l++
            }
            if (r % 2 != 0) {
                r--
                lazyMul[r] *= Num(2)
                sumVal[r] *= Num(2)
            }

            l /= 2
            r /= 2
        }
        updateAll(y)
        updateAll(L-1)

        // sum from [x, y) -> dump it in y
        var sum = Num(0)

        propogateAll(x)
        propogateAll(y-1)
        l = L + x
        r = L + y
        while (l < r) {
            if (l % 2 != 0) {
                sum += sumVal[l]
                l++
            }
            if (r % 2 != 0) {
                r--
                sum += sumVal[r]
            }

            l /= 2
            r /= 2
        }

        propogateAll(y)
        sumVal[L + y] += sum
        updateAll(y)

        lastSeen = maxOf(lastSeen, y)
    }

    propogateAll(lastSeen)
    return sumVal[L + lastSeen]
}

fun main() {
    val ans = go()
    outputLn("${ans.v}")
    println(OUTPUT_LINES.joinToString("\n"))
}