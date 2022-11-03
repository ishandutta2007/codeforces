import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases){
        val a = br.readInt()
        val b = br.readInt()
        if(a >= 2 * b){
            sb.append(b).append('\n')
        } else if(b >= 2 * a){
            sb.append(a).append('\n')
        } else {
            sb.append((a + b) / 3).append('\n')
        }
    }

    print(sb)
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