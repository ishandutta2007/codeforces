import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val cts = IntArray(30)
        repeat(n) {
            val num = br.readInt()
            for (x in 0 until 30) {
                if ((1 shl x) and num != 0) {
                    cts[x]++
                }
            }
        }
        var decidingBit = 30
        for (x in 29 downTo 0) {
            if (cts[x] and 1 == 1) {
                decidingBit = x
                break
            }
        }
        if (decidingBit == 30) {
            sb.append("DRAW\n")
        } else {
            if(cts[decidingBit] and 3 == 1 || n and 1 == 0){
                sb.append("WIN\n")
            } else {
                sb.append("LOSE\n")
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