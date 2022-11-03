import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val cons = Array(n) { mutableListOf<Int>() }
    val inCt = IntArray(n)
    repeat(m) {
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        inCt[b]++
        cons[a].add(b)
    }
    var numProcessed = 0
    val queue = ArrayDeque<Int>()
    for (x in 0 until n) {
        if (inCt[x] == 0) {
            queue += x
        }
    }
    while (queue.isNotEmpty()) {
        val node = queue.removeFirst()
        numProcessed++
        for (adj in cons[node]) {
            inCt[adj]--
            if (inCt[adj] == 0) {
                queue += adj
            }
        }
    }
    var good = numProcessed == n
    val savedData = IntArray(n) { idx -> inCt[idx] }
    val savedProcessed = numProcessed
    for (x in 0 until n) {
        if (savedData[x] == 1) {
            inCt[x]--
            queue += x
            while (queue.isNotEmpty()) {
                val node = queue.removeFirst()
                numProcessed++
                for (adj in cons[node]) {
                    inCt[adj]--
                    if (inCt[adj] == 0) {
                        queue += adj
                    }
                }
            }
            if (numProcessed == n) good = true
            numProcessed = savedProcessed
            for (y in 0 until n) {
                inCt[y] = savedData[y]
            }
        }
    }
    if (good) {
        println("YES")
    } else {
        println("NO")
    }

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