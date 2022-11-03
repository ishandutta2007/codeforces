import java.io.BufferedReader
import kotlin.math.sign

fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readInt()
    val sb = StringBuilder()
    repeat(numCases){
        val n = br.readInt()
        val path = mutableListOf(br.readInt())
        var dir = 0
        repeat(n - 1){
            val num = br.readInt()
            val newDir = (num - path.last()).sign
            if(dir == newDir){
                path[path.lastIndex] = num
            } else {
                path += num
            }
            dir = newDir
        }
        sb.append(path.size).append('\n').append(path.joinToString(" ")).append('\n')
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