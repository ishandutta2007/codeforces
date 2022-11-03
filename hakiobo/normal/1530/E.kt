import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val s = br.readLine()
        val n = s.length
        val counts = IntArray(26)
        for (c in s) {
            counts[c - 'a']++
        }
        var bestC = 'a'
        var bestScore = 2
        for (x in 0 until 26) {
            if (counts[x] == 0) {
                continue
            } else if (counts[x] == 1) {
                bestScore = 0
                bestC = 'a' + x
                sb.append(bestC)
                counts[x]--
                break
            } else if (counts[x] < n && bestScore == 2) {
                bestScore = 1
                bestC = 'a' + x
            }
        }
        if (bestScore == 2) {
            sb.appendLine(s)
        } else if (bestScore == 0) {
            for (x in 0 until 26) {
                if (counts[x] != 0) {
                    val c = 'a' + x
                    sb.append(c.toString().repeat(counts[x]))
                }
            }
            sb.appendLine()
        } else {
            val bestIdx = bestC - 'a'
            counts[bestIdx]--
            sb.append(bestC)
            if (counts[bestIdx] shl 1 <= n) {
                sb.append(bestC)
                counts[bestIdx]--
                var idx = bestIdx + 1
                while (counts[bestIdx] > 0) {
                    while (counts[idx] == 0) {
                        idx++
                    }
                    sb.append('a' + idx)
                    counts[idx]--
                    sb.append(bestC)
                    counts[bestIdx]--
                }
                for (x in idx until 26) {
                    if (counts[x] != 0) {
                        val c = 'a' + x
                        sb.append(c.toString().repeat(counts[x]))
                    }
                }
                sb.appendLine()
            } else {
                var numOthers = 0
                var firstOther = -1
                var secondOther = -1
                for (x in bestIdx + 1 until 26) {
                    if (counts[x] != 0) {
                        numOthers++
                        if (numOthers == 1) {
                            firstOther = x
                        } else if (numOthers == 2) {
                            secondOther = x
                        }
                    }
                }
                if (numOthers >= 2) {
                    sb.append('a' + firstOther)
                    counts[firstOther]--
                    sb.append(bestC.toString().repeat(counts[bestIdx]))
                    sb.append('a' + secondOther)
                    counts[secondOther]--
                    for (x in (bestIdx + 1) until 26) {
                        if (counts[x] != 0) {
                            val c = 'a' + x
                            sb.append(c.toString().repeat(counts[x]))
                        }
                    }
                    sb.appendLine()
                } else {
                    sb.append(('a' + firstOther).toString().repeat(counts[firstOther]))
                    sb.appendLine(bestC.toString().repeat(counts[bestIdx]))
                }
            }
        }
    }
    print(sb)
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