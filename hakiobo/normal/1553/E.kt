import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        val perm = IntArray(n) { br.readInt() - 1 }
        val score = IntArray(n)
        for (x in 0 until n) {
            score[(x - perm[x] + n) % n]++
        }
        val answers = mutableListOf<Int>()
        for (shift in 0 until n) {
            if (score[shift] >= n - (m shl 1)) {
                val dupe = IntArray(n) { idx -> perm[idx] }
                var swaps = 0
                var temp: Int

                for (y in 0 until n) {
                    while (dupe[y] != (y - shift + n) % n) {
                        temp = dupe[y]
                        dupe[y] = dupe[(temp + shift) % n]
                        dupe[(temp + shift) % n] = temp
                        swaps++
                    }
                }
                if (swaps <= m) {
                    answers += shift
                }
            }
        }
        sb.appendLine("${answers.size} ${answers.joinToString(" ")}")
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