import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val b = br.readInt()
    val k = br.readInt()
    val nums = IntArray(k) { br.readInt() and 1 }
    val odd = if (b and 1 == 0) {
        nums.last() and 1 == 1
    } else {
        nums.sum() and 1 == 1
    }
    if(odd){
        print("odd")
    } else {
        print("even")
    }
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