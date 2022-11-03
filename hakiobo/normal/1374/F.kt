import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val steps = mutableListOf<Int>()

        fun doMoves(idx: Int) {
            steps += idx + 1
            val tmp = a[idx]
            a[idx] = a[idx + 2]
            a[idx + 2] = a[idx + 1]
            a[idx + 1] = tmp
        }

        val sorted = a.sorted()
        var prev = sorted.first()
        var repeatLeft = 0
        var repeatRight = 2
        for (x in 1 until sorted.size) {
            if (sorted[x] == prev) {
                if (x != 1) {
                    repeatLeft = x - 2
                    repeatRight = x
                }
            }
            prev = sorted[x]
        }
        for (x in 0 until repeatLeft) {
            val num = sorted[x]
            var curIdx = -1
            for (y in n - 1 downTo 0) {
                if (a[y] == num) {
                    curIdx = y
                    break
                }
            }
            while (curIdx >= x + 2) {
                doMoves(curIdx - 2)
                curIdx -= 2
            }
            if (curIdx == x + 1) {
                doMoves(x)
                doMoves(x)
            }
        }
        for (x in n - 1 downTo repeatRight + 1) {
            val num = sorted[x]
            var curIdx = -1
            for (y in repeatLeft until n) {
                if (a[y] == num) {
                    curIdx = y
                    break
                }
            }
            while (curIdx < x - 1) {
                doMoves(curIdx)
                curIdx++
            }
            if (curIdx == x - 1) {
                doMoves(x - 2)
            }
        }
        var good = false
        for (x in 0 until 3) {
            if (a[repeatLeft] <= a[repeatLeft + 1] && a[repeatLeft + 1] <= a[repeatRight]) {
                sb.append(steps.size).append('\n').append(steps.joinToString(" ")).append('\n')
                good = true
                break
            }
            doMoves(repeatLeft)
        }
        if (!good) {
            sb.append("-1\n")
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