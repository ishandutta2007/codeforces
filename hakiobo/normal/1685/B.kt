import java.io.BufferedReader

fun main() {
    val aInt = 'A'.toInt()
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val a = br.readInt()
        val b = br.readInt()
        val ab = br.readInt()
        val ba = br.readInt()
        val n = a + b + ((ab + ba) shl 1)
        val word = IntArray(n) { br.read() - aInt }
        br.read()

        var aCt = 0
        var bCt = 0
        for (c in word) {
            if (c == 0) aCt++ else bCt++
        }
        if (a + ab + ba != aCt) {
            bw.appendLine("NO")
        } else {
            val abLens = IntArray(n + 1)
            val baLens = IntArray(n + 1)
            val eqLens = IntArray(n + 1)
            var startIdx = 0
            var prev = word[startIdx]

            for (i in 1 until n) {
                val c = word[i]
                if (c == prev) {
                    val startC = word[startIdx]
                    val len = i - startIdx
                    if (prev == startC) {
                        eqLens[len]++
                    } else if (startC == 0) {
                        abLens[len]++
                    } else {
                        baLens[len]++
                    }
                    startIdx = i
                }
                prev = c
            }
            val startC = word[startIdx]
            val len = n - startIdx
            if (prev == startC) {
                eqLens[len]++
            } else if (startC == 0) {
                abLens[len]++
            } else {
                baLens[len]++
            }
            var abNeeded = ab
            var baNeeded = ba
            var abIdx = 0
            while ((abNeeded > 0 || baNeeded > 0) && abIdx <= n) {
                if (abLens[abIdx] == 0) abIdx += 2 else {
                    val forAB = abIdx shr 1
                    if (forAB <= abNeeded) {
                        abNeeded -= forAB
                        abLens[abIdx]--
                    } else if (forAB - 1 - abNeeded <= baNeeded) {
                        baNeeded -= forAB - abNeeded - 1
                        abNeeded = 0
                        abLens[abIdx]--
                    } else {
                        abNeeded = 0
                        baNeeded = 0
                        abLens[abIdx]--
                    }
                }
            }
            var baIdx = 0

            while ((abNeeded > 0 || baNeeded > 0) && baIdx <= n) {
                if (baLens[baIdx] == 0) baIdx += 2 else {
                    val forBA = baIdx shr 1
                    if (forBA <= baNeeded) {
                        baNeeded -= forBA
                        baLens[baIdx]--
                    } else if (forBA - 1 - baNeeded <= abNeeded) {
                        abNeeded -= forBA - baNeeded - 1
                        baNeeded = 0
                        baLens[baIdx]--
                    } else {
                        abNeeded = 0
                        baNeeded = 0
                        baLens[baIdx]--
                    }
                }
            }
            var eqIdx = 1
            while ((abNeeded > 0 || baNeeded > 0) && eqIdx <= n) {
                if (eqLens[eqIdx] == 0) eqIdx += 2 else {
                    val forEither = eqIdx shr 1
                    if (forEither <= baNeeded) {
                        baNeeded -= forEither
                        eqLens[eqIdx]--
                    } else if (forEither - baNeeded <= abNeeded) {
                        abNeeded -= forEither - baNeeded
                        baNeeded = 0
                        eqLens[eqIdx]--
                    } else {
                        abNeeded = 0
                        baNeeded = 0
                        eqLens[eqIdx]--
                    }
                }
            }
            if (abNeeded == 0 && baNeeded == 0) {
                bw.appendLine("YES")
            } else {
                bw.appendLine("NO")
            }
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