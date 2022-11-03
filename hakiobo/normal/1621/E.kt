import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val tAges = LongArray(n) { br.readInt().toLong() }.sortedDescending().toLongArray()
        val studentAges = Array(m) {
            val k = br.readInt()
            LongArray(k) { br.readInt().toLong() }
        }
        val sums = LongArray(m) { i ->
            studentAges[i].sum()
        }
        val sorted = (0 until m).sortedWith { a, b ->
            val aThing = sums[a] * studentAges[b].size
            val bThing = sums[b] * studentAges[a].size
            bThing.compareTo(aThing)
        }

        fun check(sIdx: Int, tIdx: Int): Int {
            return if (tIdx in 0 until n && tAges[tIdx] * studentAges[sIdx].size >= sums[sIdx]) {
                1
            } else {
                0
            }
        }

        val leftShift = IntArray(m + 1)
        val rightShift = IntArray(m + 1)
        val noShift = IntArray(m + 1)
        for (x in 0 until m) {
            val s = sorted[x]
            leftShift[x + 1] = leftShift[x]
            rightShift[x + 1] = rightShift[x]
            noShift[x + 1] = noShift[x]
            leftShift[x + 1] += check(s, x - 1)
            noShift[x + 1] += check(s, x)
            rightShift[x + 1] += check(s, x + 1)
        }
        val rev = IntArray(m)
        for (x in 0 until m) {
            rev[sorted[x]] = x
        }

        for (group in 0 until m) {
            val newSize = studentAges[group].size - 1
            val oldSpot = rev[group]

            for (sIdx in studentAges[group].indices) {
                val newSum = sums[group] - studentAges[group][sIdx]
                var low = 0
                var high = m
                while (low < high) {
                    val mid = (low + high) shr 1
                    val other = sorted[mid]
                    val oSize = studentAges[other].size
                    val oSum = sums[other]
                    if (oSize * newSum < newSize * oSum) {
                        low = mid + 1
                    } else {
                        high = mid
                    }
                }
                var newSpot = high
                var ct = 0
                if (oldSpot < newSpot) {
                    newSpot--
                    ct += noShift[oldSpot]
                    ct += leftShift[newSpot + 1] - leftShift[oldSpot + 1]
                    ct += noShift[m] - noShift[newSpot + 1]
                } else {
                    ct += noShift[newSpot]
                    ct += rightShift[oldSpot] - rightShift[newSpot]
                    ct += noShift[m] - noShift[oldSpot + 1]
                }
                if (tAges[newSpot] * newSize >= newSum) {
                    ct++
                }
                if (ct == m) {
                    sb.append(1)
                } else {
                    sb.append(0)
                }
            }
        }
        sb.appendLine()

    }
    println(sb)
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