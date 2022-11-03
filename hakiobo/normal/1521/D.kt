import java.io.BufferedReader
import kotlin.system.exitProcess

private data class TreeMove(val uRem: Int, val vRem: Int, val uAdd: Int, val vAdd: Int) {
    override fun toString(): String {
        return "${uRem + 1} ${vRem + 1} ${uAdd + 1} ${vAdd + 1}"
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val cons = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val u = br.readInt() - 1
            val v = br.readInt() - 1
            cons[u] += v
            cons[v] += u
        }
        val moves = mutableListOf<TreeMove>()
        val dp1 = IntArray(n) { -1 }
        val dp2 = IntArray(n) { -1 }
        val parent = IntArray(n) { -1 }
        fun r(node: Int) {
            var holdChild = -1
            for (child in cons[node]) {
                if (child != parent[node]) {
                    parent[child] = node
                    r(child)
                    if (dp2[child] == -1) {
                        if (holdChild != -1) {
                            moves += TreeMove(node, holdChild, dp1[child], dp2[holdChild])
                            dp1[node] = dp1[holdChild]
                            holdChild = -1
                        } else if (dp1[node] == -1) {
                            dp1[node] = dp1[child]
                        } else if (dp2[node] == -1) {
                            dp2[node] = dp1[child]
                        } else {
                            moves += TreeMove(node, child, dp2[node], dp1[child])
                            dp2[node] = child
                        }
                    } else if (holdChild != -1) {
                        moves += TreeMove(node, child, dp1[child], dp2[holdChild])
                        dp2[holdChild] = dp2[child]
                    } else if (dp1[node] == -1) {
                        holdChild = child
                    } else if(dp2[node] == -1){
                        moves += TreeMove(node, child, dp1[node], dp1[child])
                        dp1[node] = dp2[child]
                    } else {
                        moves += TreeMove(node, child, dp2[node], dp1[child])
                        dp2[node] = dp2[child]
                    }
                }
            }
            if (holdChild != -1) {
                moves += TreeMove(node, holdChild, node, dp2[holdChild])
                dp1[node] = dp1[holdChild]
            }
            if (dp1[node] == -1) {
                dp1[node] = node
            }
        }
        r(0)
        sb.append(moves.size).append("\n")
        sb.append(moves.joinToString("\n")).append("\n")
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