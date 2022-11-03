import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val strs = Array(n) { br.readLine() }
        var zCt = 0
        var oCt = 0
        var anyOdd = false
        for(i in 0 until n) {
            if(strs[i].length and 1 ==1 ) anyOdd = true
            for(c in strs[i]) {
                if(c == '0') {
                    zCt++
                } else {
                    oCt++
                }
            }
        }
        if(anyOdd || zCt and 1 == 0) {
            bw.appendLine(n.toString())
        } else {
            bw.appendLine((n - 1).toString())
        }
    }
    bw.flush()
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