import java.io.BufferedReader
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val a = LongArray(n) { br.readInt().toLong() }
    val b = IntArray(n) { br.readInt() - 1 }
    val incoming = IntArray(n)
    for (x in b) {
        if (x != -2) {
            incoming[x]++
        }
    }
    val queue: Queue<Int> = ArrayDeque()
    val laterMoves: Deque<Int> = ArrayDeque()
    for (x in 0 until n) {
        if (incoming[x] == 0) {
            queue += x
        }
    }
    var ans = 0L
    val moves = IntArray(n)
    var movesMade = 0
    while (queue.isNotEmpty()) {
        val idx = queue.poll()
        if (a[idx] >= 0) {
            moves[movesMade++] = idx + 1
            ans += a[idx]
            if (b[idx] != -2) {
                a[b[idx]] += a[idx]
            }
        } else {
            laterMoves.addFirst(idx)
        }
        if (b[idx] != -2) {
            incoming[b[idx]]--
            if (incoming[b[idx]] == 0) {
                queue += b[idx]
            }
        }

    }
    while (laterMoves.isNotEmpty()) {
        val idx = laterMoves.pollFirst()
        moves[movesMade++] = idx + 1
        ans += a[idx]
    }
    sb.append(ans).append('\n')
    sb.append(moves.joinToString(" ")).append('\n')
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