import java.io.BufferedReader
import kotlin.concurrent.fixedRateTimer

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    for(whatever in 0 until t){
        val n = br.readInt()
        val perm = IntArray(n)
        val cts = IntArray(n)
        val lists = Array(n) { mutableListOf<Int>() }
        val parts = Array(n - 1) { idx ->
            IntArray(br.readInt()) {
                val i = br.readInt() - 1
                cts[i]++
                lists[i].add(idx)
                i
            }
        }
        val analysisOrder = IntArray(n - 1) { -1 }

        fun validate(): Boolean {
            for (x in 0 until n - 1) {
                val group = parts[analysisOrder[x]]
                val things = List(group.size) { idx ->
                    perm[n - 1 - x - idx] - 1
                }.sorted().toIntArray()
                if (!things.contentEquals(group)) {
                    return false
                }
            }
            return true
        }

        val analyzed = BooleanArray(n - 1)
        fun solve(idx: Int, toAdd: Int): Boolean {
            perm[idx] = toAdd + 1
            var yToAnalyze = -1
            for (y in lists[toAdd]) {
                if (!analyzed[y]) {
                    yToAnalyze = y
                    analysisOrder[n - 1 - idx] = y
                    analyzed[y] = true
                }
            }

            val reducedToOne = mutableListOf<Int>()
            var toZero = -1

            for (x in parts[yToAnalyze]) {
                cts[x]--
                if (cts[x] == 1) {
                    reducedToOne += x
                }
                if (cts[x] == 0 && x != toAdd) {
                    toZero = x
                }
            }

            if (toZero != -1 && idx == 1) {
                perm[0] = toZero + 1
                if (validate()) {
                    return true
                }
            }

            for (x in reducedToOne) {
                if (solve(idx - 1, x)) {
                    return true
                }
            }

            for (x in parts[yToAnalyze]) {
                cts[x]++
            }
            analyzed[yToAnalyze] = false

            return false
        }
        for (x in 0 until n) {
            if (cts[x] == 1 && solve(n - 1, x)) {
                sb.append(perm.joinToString(" ")).append('\n')
                break
            }
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

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

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}