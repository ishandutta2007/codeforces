import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val cons = Array(n) { mutableListOf<Int>() }
    repeat(m) {
        val u = br.readInt() - 1
        val v = br.readInt() - 1
        cons[u].add(v)
        cons[v].add(u)
    }
    val colors = IntArray(n) { -1 }
    val ans = Array(2) { mutableListOf<Int>() }
    val queue = ArrayDeque<Int>()
    var good = true
    for (x in 0 until n) {
        if (colors[x] == -1) {
            colors[x] = 1
            queue.addLast(x)

            while (queue.isNotEmpty()) {
                val cur = queue.removeFirst()
                val color = colors[cur]
                ans[color].add(cur + 1)
                for (adj in cons[cur]) {
                    when (colors[adj]) {
                        -1 -> {
                            colors[adj] = color xor 1
                            queue.addLast(adj)
                        }
                        color -> {
                            good = false
                        }
                    }
                }
            }
        }
    }
    if (good) {
        for (x in 0 until 2) {
            println(ans[x].size)
            println(ans[x].joinToString(" "))
        }
    } else {
        println(-1)
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