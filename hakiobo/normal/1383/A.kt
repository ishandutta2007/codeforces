import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val a = br.readLine().toCharArray()
        val b = br.readLine().toCharArray()
        val dif = BooleanArray(20)
        var possible = true
        var moves = 0
        for (c in 0 until 20) {
            var lowC = 20
            for (x in 0 until n) {
                if (a[x] - 'a' == c) {
                    if (a[x] > b[x]) {
                        possible = false
                    } else if (a[x] != b[x]) {
                        lowC = lowC.coerceAtMost(b[x] - 'a')
                    }
                }
            }
            if (lowC != 20) {
                moves++
                for (x in 0 until n) {
                    if (a[x] - 'a' == c && a[x] != b[x]) {
                        a[x] = 'a' + lowC
                    }
                }
            }
        }

        if(possible){
            sb.append(moves).append('\n')
        } else {
            sb.append("-1\n")
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