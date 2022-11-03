import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val counts = IntArray(20)
    repeat(n) {
        val num = br.readInt()
        for (x in 0 until 20) {
            if (1 shl x and num != 0) {
                counts[x]++
            }
        }
    }
    var sum = 0L
    repeat(n) {
        var num = 0L
        for (x in 0 until 20) {
            if (counts[x] != 0) {
                counts[x]--
                num = num or (1L shl x)
            }
        }
        sum += num * num
    }
    print(sum)
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

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}