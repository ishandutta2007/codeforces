import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val x = br.readInt().toLong()
        val divis = Array(2) { mutableListOf<Long>() }
        val notDivis = Array(2) { mutableListOf<Long>() }
        repeat(n) {
            val num = br.readInt().toLong()
            if (num % x == 0L) {
                divis[0].add(num / x)
            } else {
                notDivis[0].add(num)
            }
        }
        divis[0].sort()
        notDivis[0].sort()
        var ans = 0
        while (divis[0].isNotEmpty()) {
            var i = 0
            var j = 0
            while (i < notDivis[0].size && j < divis[0].size) {
                if (notDivis[0][i] == divis[0][j]) {
                    i++
                    j++
                } else if (notDivis[0][i] < divis[0][j]) {
                    ans++
                    i++
                } else {
                    if (divis[0][j] % x == 0L) {
                        divis[1].add(divis[0][j] / x)
                    } else {
                        notDivis[1].add(divis[0][j])
                    }
                    j++
                }
            }
            while (i < notDivis[0].size) {
                ans++
                i++
            }
            while (j < divis[0].size) {
                if (divis[0][j] % x == 0L) {
                    divis[1].add(divis[0][j] / x)
                } else {
                    notDivis[1].add(divis[0][j])
                }
                j++
            }
            var temp = divis[0]
            divis[0] = divis[1]
            divis[1] = temp
            divis[1].clear()
            temp = notDivis[0]
            notDivis[0] = notDivis[1]
            notDivis[1] = temp
            notDivis[1].clear()
        }
        ans += notDivis[0].size
        sb.appendLine(ans)
    }
    println(sb)
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