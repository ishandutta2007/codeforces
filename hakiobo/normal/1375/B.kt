import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val m = br.readInt()
        var good = true
        val grid = Array(n) { IntArray(m) { br.readInt() } }
        for(row in 0 until n){
            for(col in 0 until m){
                var numNeeded = 2
                if(row in 1 until (n - 1)){
                    numNeeded++
                }
                if(col in 1 until (m - 1)){
                    numNeeded++
                }
                if(numNeeded < grid[row][col]){
                    good = false
                } else {
                    grid[row][col] = numNeeded
                }
            }
        }
        if(good){
            sb.append("YES\n")
            repeat(n){row ->
                sb.append(grid[row].joinToString(" ")).append('\n')
            }
        } else {
            sb.append("NO\n")
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