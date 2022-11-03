import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readInt()
    val answer = IntArray(numCases) {
        val n = br.readInt()
        val x = br.readInt()

        var firstNon = -1
        var lastNon = -1
        var sum = 0
        for (i in 0 until n) {
            val num = br.readInt()
            if (num % x != 0) {
                if (firstNon == -1) firstNon = i
                lastNon = i
            }
            sum += num
        }
        if (sum % x == 0){
            if(firstNon == -1){
                -1
            } else {
                lastNon.coerceAtLeast(n - firstNon - 1)
            }
        } else {
            n
        }
    }
    print(answer.joinToString("\n"))
}


private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
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
    while (read <= SPACE_INT && read != -1) {
        mark(1)
        read = read()
        if (read == NL_INT) {
            read = -1
            break
        }
    }
    if (read != -1) {
        reset()
    }
    return if (neg) -ret else ret
}