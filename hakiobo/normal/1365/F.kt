import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()

    fun comp(a: Pair<Int, Int>, b: Pair<Int, Int>): Int {
        return if (a.first.compareTo(b.first) != 0) {
            a.first.compareTo(b.first)
        } else {
            a.second.compareTo(b.second)
        }
    }
    repeat(numCases) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val b = IntArray(n) { br.readInt() }
        var valid = true
        if (n and 1 == 1) {
            val mid = n shr 1
            if (a[mid] != b[mid]) {
                valid = false
            }
        }
        val aThing = mutableListOf<Pair<Int, Int>>()
        val bThing = mutableListOf<Pair<Int, Int>>()
        for (x in 0 until (n shr 1)) {
            val (aLow, aHigh) = listOf<Int>(a[x], a[n - 1 - x]).sorted()
            val (bLow, bHigh) = listOf<Int>(b[x], b[n - 1 - x]).sorted()

            aThing += Pair(aLow, aHigh)
            bThing += Pair(bLow, bHigh)
        }
        aThing.sortWith(Comparator(::comp))
        bThing.sortWith(Comparator(::comp))
        for (x in aThing.indices) {
            if (aThing[x] != bThing[x]) {
                valid = false
                break
            }
        }
        if (valid) {
            sb.append("Yes\n")
        } else {
            sb.append("No\n")
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