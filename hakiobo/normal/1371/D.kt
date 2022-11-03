import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        val fulDiags = k/n
        val leftOver = k%n
        val grid = Array(n){ IntArray(n) }
        for(diag in 0 until fulDiags){
            for(x in 0 until n){
                grid[(diag + x)%n][x] = 1
            }
        }
        if(leftOver == 0){
            sb.append("0\n")
        } else {
            sb.append("2\n")
            for(x in 0 until leftOver){
                grid[(fulDiags + x)%n][x] = 1
            }
        }
        for(x in 0 until n){
            sb.append(grid[x].joinToString("")).append('\n')
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