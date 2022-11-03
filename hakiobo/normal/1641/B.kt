import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val sorted = a.sorted()
        var cur = sorted.first()
        var strk = 1
        var bad = false
        for (x in 1 until n) {
            if (cur == sorted[x]) {
                strk++
            } else if (strk and 1 == 1) {
                bad = true
            } else {
                strk = 1
                cur = sorted[x]
            }
        }
        if (strk and 1 == 1) {
            bad = true
        }
        if (bad) {
            bw.appendLine("-1")
        } else {
            val moveIds = mutableListOf<Int>()
            val moveVals = mutableListOf<Int>()
            val rangeSizes = mutableListOf<Int>()
            var i = 0
            var offset = 0
            while (i < n) {
                val base = i
                i++
                while (a[i] != a[base]) {
                    i++
                }
                var dif = 1
                while (i + dif < n && base + dif < i && a[base + dif] == a[i + dif]) {
                    dif++
                }
                val movesToMake = i - (base + dif)
                for (x in 0 until movesToMake) {
                    moveIds += offset + i + dif + x
                    moveVals += a[base + dif + x]
                }
                var startRev = base + dif
                var endRev = i + dif - 1
                while (startRev < endRev) {
                    val temp = a[startRev]
                    a[startRev] = a[endRev]
                    a[endRev] = temp
                    startRev++
                    endRev--
                }
                offset += movesToMake shl 1
                rangeSizes += (i - base) shl 1
                i += dif - movesToMake
            }

            bw.appendLine("${moveIds.size}")
            for (j in moveIds.indices) {
                bw.appendLine("${moveIds[j]} ${moveVals[j]}")
            }
            bw.appendLine("${rangeSizes.size}")
            bw.append(rangeSizes.first().toString())
            for (j in 1 until rangeSizes.size) {
                bw.append(" ${rangeSizes[j]}")
            }
            bw.newLine()
        }
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