import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = IntArray(n) { br.readInt() }
    val nextKnown = IntArray(n)
    var firstKnown = n
    for (i in n - 1 downTo 0) {
        nextKnown[i] = firstKnown
        if (a[i] != -1) {
            firstKnown = i
        }
    }
    val prevKnown = IntArray(n)
    var lastKnown = -1
    for (i in 0 until n) {
        prevKnown[i] = lastKnown
        if (a[i] != -1) {
            lastKnown = i
        }
    }
    val startOfNext = IntArray(n) { i ->
        if (a[i] == -1 && nextKnown[i] != n) {
            nextKnown[nextKnown[i]]
        } else {
            nextKnown[i]
        }
    }
    var cur = firstKnown
    while (cur != n) {
        val extendsForward = run {
            if (nextKnown[cur] != n) {
                val dif = nextKnown[cur] - cur
                val valDif = a[nextKnown[cur]] - a[cur]
                valDif % dif == 0
            } else {
                false
            }
        }

        if (extendsForward) {
            val difPer = (a[nextKnown[cur]] - a[cur]) / (nextKnown[cur] - cur)
            val extendsBack = run {
                if (prevKnown[cur] != -1) {
                    val dif2 = cur - prevKnown[cur]
                    val valDif2 = a[cur] - a[prevKnown[cur]]
                    valDif2 % dif2 == 0 && valDif2 / dif2 == difPer
                } else {
                    false
                }
            }
            if (!extendsBack) {
                val leftEdge = if (difPer <= 0) prevKnown[cur] + 1 else {
                    max(prevKnown[cur] + 1, cur - ((a[cur] - 1) / difPer))
                }
                var rightEdge = nextKnown[cur]
                while (nextKnown[rightEdge] != n && (a[nextKnown[rightEdge]] - a[cur]) % (nextKnown[rightEdge] - cur) == 0 && (a[nextKnown[rightEdge]] - a[cur]) / (nextKnown[rightEdge] - cur) == difPer) {
                    rightEdge = nextKnown[rightEdge]
                }
                val rightEdgeEx = if (difPer >= 0) nextKnown[rightEdge] else min(
                    nextKnown[rightEdge],
                    1 + cur - (a[cur] - 1) / difPer
                )
                for (i in leftEdge until rightEdgeEx) {
                    startOfNext[i] = max(startOfNext[i], rightEdgeEx)
                }
            }
        }
        cur = nextKnown[cur]
    }
    cur = 0
    var ans = 0
    while (cur != n) {
        ans++
        cur = startOfNext[cur]
    }

    println(ans)
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