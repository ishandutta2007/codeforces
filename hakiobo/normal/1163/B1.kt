import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val colors = IntArray(n) { br.readInt() }
    val ct = IntArray(100_001)
    val atCount = IntArray(n + 2)
    var answer = 0
    var distinct = 0
    for (x in 0 until n) {
        val color = colors[x]
        if (ct[color] == 0) {
            distinct++
        } else {
            atCount[ct[color]]--
        }
        ct[color]++
        val count = ct[color]
        atCount[count]++
        if (atCount[1] == distinct) {
            answer = x
        } else if (distinct == 1) {
            answer = x
        } else {
            if (x % distinct == 0) {
                val check = x / distinct
                if (atCount[check] == distinct - 1 && atCount[check + 1] == 1) {
                    answer = x
                }
            }
            if (x % (distinct - 1) == 0) {
                val check = x / (distinct - 1)
                if (atCount[check] == distinct - 1 && atCount[1] == 1){
                    answer = x
                }
            }
        }
    }
    println(answer + 1)
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