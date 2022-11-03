import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine().toCharArray()
        var allSame = true
        val first = s.first()
        var start = 0
        for (x in 1 until n) {
            if (s[x] != first) {
                start = x
                allSame = false
                break
            }
        }
        if (allSame) {
            sb.append((n + 2) / 3).append('\n')
        } else {
            var curStreak = 1
            var prev = s[start]
            var changes = 0
            for (x in 1 until n) {
                val cur = s[(start + x) % n]
                if (prev == cur) {
                    curStreak++
                    if (curStreak == 3) {
                        changes++
                        curStreak = 0
                    }
                } else {
                    curStreak = 1
                    prev = cur
                }
            }
            sb.append(changes).append('\n')
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