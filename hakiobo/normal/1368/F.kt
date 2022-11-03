import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()

    val n = br.readInt()
    var start = 1
    val move = mutableListOf<Int>()
    val active = BooleanArray(n)
    var mod = 2

    fun doMove(): Int {
        if (move.size < mod) {
            println(0)
            return 0
        }
        println("%d %s".format(move.size, move.joinToString(" ")))
        val num = br.readInt()
        for (x in 0 until move.size) {
            active[(x + num) % n] = false
        }
        move.clear()

        return num
    }

    var r = 0
    while (true) {
        val new = ((n * (mod - 1)) / mod) - (mod - 1)
        if (new < r) {
            break
        } else {
            r = new
            mod++
        }
    }
    mod--
    do {
        for (x in 0 until n) {
            if (x % mod != 0 && !active[x]) {
                active[x] = true
                move += x
            }
        }
    } while (doMove() > 0)
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

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}