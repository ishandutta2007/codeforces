import java.io.BufferedReader
import java.util.*
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        val da = br.readInt()
        val db = br.readInt()
        val cons = Array(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u].add(v)
            cons[v].add(u)
        }
        if (db <= da * 2) {
            sb.append("Alice\n")
        } else {
            val distsFromBob = IntArray(n)
            val bobPrev = IntArray(n) { -1 }
            distsFromBob[b] = 0
            val queue = ArrayDeque<Int>()
            queue.add(b)
            var furth = b
            while (queue.isNotEmpty()) {
                val cur = queue.poll()
                val dist = distsFromBob[cur]
                for (adj in cons[cur]) {
                    if (adj != bobPrev[cur]) {
                        distsFromBob[adj] = dist + 1
                        bobPrev[adj] = cur
                        queue += adj
                    }
                }
                if (distsFromBob[cur] > distsFromBob[furth]) {
                    furth = cur
                }

            }
            if (distsFromBob[a] <= da) {
                sb.append("Alice\n")
            } else {
                val dist2 = IntArray(n)
                val prev2 = IntArray(n) { -1 }
                var diam = 0
                queue += furth
                while (queue.isNotEmpty()) {
                    val cur = queue.poll()
                    for (adj in cons[cur]) {
                        if (adj != prev2[cur]) {
                            dist2[adj] = dist2[cur] + 1
                            prev2[adj] = cur
                            queue += adj
                        }
                    }
                    diam = max(diam, dist2[cur])
                }
                if (diam > 2 * da){
                    sb.append("Bob\n")
                } else {
                    sb.append("Alice\n")
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