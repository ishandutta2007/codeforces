import java.io.BufferedReader
import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val wish = IntArray(n) { br.readInt() - 1 }
        val rev = Array(n) { mutableListOf<Int>() }
        val desired = IntArray(n)
        val taken = BooleanArray(n)
        val answer = IntArray(n)
        for (x in 0 until n) {
            val y = wish[x]
            rev[y].add(x)
            desired[y]++
        }
//        val freeToAssign = ArrayDeque<Int>()
        val safeQueue = ArrayDeque<Int>()
//        for (x in 0 until n) {
//            if (rev[x].size == 1) {
//                taken[x] = true
//                answer[rev[x].first()] = x + 1
////                freeToAssign += rev[x].first()
//            } else if (rev[x].isEmpty()) {
//                danger += x
//            }
//        }

        var ansSize = 0
        val toAssignQueue = ArrayDeque<Int>()
        for (x in 0 until n) {
            var toAdd = -1
            var good = false
            for (y in rev[x]) {
                if (rev[y].isEmpty()) {
                    toAdd = y
                    good = true
                } else if (!good) {
                    toAdd = y
                }
            }
            if (toAdd != -1) {
                ansSize++
                taken[x] = true
                answer[toAdd] = x + 1
            }
        }
        for (x in 0 until n) {
            if (!taken[x]) {
                if (answer[x] == 0) {
                    toAssignQueue.addLast(x)
                } else {
                    safeQueue += x
                }
            } else if (answer[x] == 0) {
                toAssignQueue.addFirst(x)
            }
        }
        while (toAssignQueue.isNotEmpty()) {
            val toAssign = toAssignQueue.removeLast()
            val assignment = safeQueue.removeLast()
            answer[toAssign] = assignment + 1
            assert(!taken[assignment])
            taken[assignment] = true
            if (!taken[toAssign]) {
                safeQueue += toAssign
            }
        }
        sb.appendLine(ansSize)
        sb.appendLine(answer.joinToString(" "))
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