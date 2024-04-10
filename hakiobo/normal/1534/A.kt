import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val grid = Array(n) { br.readLine().toCharArray() }
        val counts = IntArray(2)
        for (row in 0 until n) {
            for (col in 0 until m) {
                when (grid[row][col]) {
                    'W' -> {
                        counts[(row + col) and 1]++
                    }
                    'R' -> {
                        counts[(1 + row + col) and 1]++
                    }
                }
            }
        }
        if (counts[0] > 0 && counts[1] > 0) {
            sb.appendLine("NO")
        } else {
            sb.appendLine("YES")
            if (counts[0] > 0) {
                for (row in 0 until n) {
                    for (col in 0 until m) {
                        if ((row + col) and 1 == 0) {
                            sb.append("W")
                        } else {
                            sb.append("R")
                        }
                    }
                    sb.appendLine()
                }
            } else {
                for (row in 0 until n) {
                    for (col in 0 until m) {
                        if ((row + col) and 1 == 1) {
                            sb.append("W")
                        } else {
                            sb.append("R")
                        }
                    }
                    sb.appendLine()
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