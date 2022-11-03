import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val grid = Array(n) { row ->
        LongArray(n) { col ->
            if (row and 1 == 0) {
                0L
            } else {
                1L shl (row + col - 1)
            }
        }
    }
    repeat(n){ row ->
        println(grid[row].joinToString(" "))
    }
    val q = br.readInt()
    repeat(q){
        val k = br.readLong()
        var row = 1
        var col = 1
        println("%d %d".format(row, col))
        for(x in 0 until (2 * n - 2)){
            if((1L shl x) and k == 0L){
                if(row and 1 == 1){
                    col++
                } else {
                    row++
                }
            } else if(row and 1 == 1){
                row++
            } else {
                col++
            }
            println("%d %d".format(row, col))
        }
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

private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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