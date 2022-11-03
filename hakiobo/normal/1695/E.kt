import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val edgeSums = IntArray(n)
    val cons = Array(2 * n) { mutableListOf<Int>() }
    for (i in 0 until n) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        edgeSums[i] = u + v
        cons[u].add(i)
        cons[v].add(i)
    }
    val ansGrid = Array(2) { IntArray(n) }
    val versionA = Array(2) { CharArray(n) }
    val versionB = Array(2) { CharArray(n) }

    val seenNum = BooleanArray(2 * n)
    val seenEdge = BooleanArray(n)
    val order = IntArray(2 * n)
    var idx = 0
    var good = true
    fun dfs(node: Int) {
        seenNum[node] = true
        for (edge in cons[node]) {
            if (!seenEdge[edge]) {
                seenEdge[edge] = true
                val adj = edgeSums[edge] - node
                if (!seenNum[adj]) {
                    order[idx++] = adj
                    dfs(adj)
                    order[idx++] = node
                } else {
                    order[idx++] = adj
                    order[idx++] = node
                }
            }
        }
    }

    for (num in 0 until 2 * n) {
        if (!seenNum[num]) {
            val baseIdx = idx
            dfs(num)
            when(val dif = idx - baseIdx) {
                0 -> {}
                2 -> good = false
                else -> {
                    val baseCol = baseIdx shr 1
                    for (i in 0 until (dif shr 1)) {
                        ansGrid[0][baseCol + i] = order[baseIdx + i] + 1
                        ansGrid[1][baseCol + i] = order[idx - i - 1] + 1
                    }
                    if (dif and 0b11 == 0) {
                        for (i in 0 until ((dif shr 1) - 1) step 2) {
                            versionA[0][baseCol + i] = 'L'
                            versionA[1][baseCol + i] = 'L'
                            versionA[0][baseCol + i + 1] = 'R'
                            versionA[1][baseCol + i + 1] = 'R'
                        }
                        for (i in 1 until ((dif shr 1) - 1) step 2) {
                            versionB[0][baseCol + i] = 'L'
                            versionB[1][baseCol + i] = 'L'
                            versionB[0][baseCol + i + 1] = 'R'
                            versionB[1][baseCol + i + 1] = 'R'
                        }
                        versionB[0][baseCol] = 'U'
                        versionB[1][baseCol] = 'D'
                        versionB[0][(idx shr 1) - 1] = 'U'
                        versionB[1][(idx shr 1) - 1] = 'D'
                    } else {
                        versionA[0][baseCol] = 'U'
                        versionA[1][baseCol] = 'D'
                        for (i in 1 until ((dif shr 1) - 1) step 2) {
                            versionA[0][baseCol + i] = 'L'
                            versionA[1][baseCol + i] = 'L'
                            versionA[0][baseCol + i + 1] = 'R'
                            versionA[1][baseCol + i + 1] = 'R'
                        }
                        for (i in 0 until ((dif shr 1) - 1) step 2) {
                            versionB[0][baseCol + i] = 'L'
                            versionB[1][baseCol + i] = 'L'
                            versionB[0][baseCol + i + 1] = 'R'
                            versionB[1][baseCol + i + 1] = 'R'
                        }
                        versionB[0][(idx shr 1) - 1] = 'U'
                        versionB[1][(idx shr 1) - 1] = 'D'
                    }
                }
            }
        }
    }

    if (!good) {
        bw.appendLine("-1")
    } else {
        bw.appendLine("2 $n")
        bw.appendLine()
        bw.appendLine(ansGrid[0].joinToString(" "))
        bw.appendLine(ansGrid[1].joinToString(" "))
        bw.appendLine()
        bw.appendLine(versionA[0].joinToString(""))
        bw.appendLine(versionA[1].joinToString(""))
        bw.appendLine()
        bw.appendLine(versionB[0].joinToString(""))
        bw.appendLine(versionB[1].joinToString(""))
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