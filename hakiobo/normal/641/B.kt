import java.io.BufferedReader
import kotlin.math.round

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readInt()
    val m = br.readInt()
    val q = br.readInt()
    val ansGrid = Array(n) { IntArray(m) }
    val queires = Array(q) { br.readLine() }
    for(i in q - 1 downTo 0) {
        val split = queires[i].split(" ")
        if(split.size == 2) {
            val (type, which) = split.map { it.toInt() - 1 }
            if(type == 0) {
                val temp = ansGrid[which].last()
                for(j in m - 1 downTo 1) {
                    ansGrid[which][j] = ansGrid[which][j - 1]
                }
                ansGrid[which][0] = temp
            } else {
                val temp = ansGrid[n - 1][which]
                for(j in n - 1 downTo 1) {
                    ansGrid[j][which] = ansGrid[j - 1][which]
                }
                ansGrid[0][which] = temp
            }
        } else {
            val (_, row, col, c) = split.map { it.toInt() - 1 }
            ansGrid[row][col] = c + 1
        }
    }
    for(row in ansGrid) {
        bw.appendLine(row.joinToString(" "))
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