import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val perm = IntArray(n) { br.readInt() - 1 }
        val revPerm = IntArray(n)
        for (x in 0 until n) {
            revPerm[perm[x]] = x
        }
        var good = true
        for (x in 0 until n) {
            if (1 and (x xor perm[x]) != 0) good = false
        }
        val moves = mutableListOf<Int>()
        fun flip(idx: Int) {
            moves += idx + 1
            val center = idx shr 1
            for (x in 0 until center) {
                val temp = perm[x]
                perm[x] = perm[idx - x]
                perm[idx - x] = temp
                revPerm[perm[x]] = x
                revPerm[perm[idx - x]] = idx - x
            }
        }
        if (!good) sb.appendLine(-1) else {
            var a = n - 1
            var b = n - 2

            while (b >= 0) {
                flip(revPerm[a])
                flip(revPerm[b] - 1)
                flip(revPerm[b] + 1)
                flip(2)
                flip(a)



                a -= 2
                b -= 2
            }
            sb.appendLine(moves.size)
            sb.appendLine(moves.joinToString(" "))
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