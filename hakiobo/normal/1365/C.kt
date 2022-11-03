import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val p1Pos = IntArray(n)
    val difs = IntArray(n)
    repeat(n) { idx ->
        val num = br.readInt() - 1
        p1Pos[num] = idx

    }
    repeat(n) { idx ->
        val num = br.readInt() - 1
        val d = (n + idx - p1Pos[num]) % n
        difs[d]++
    }
    print(difs.max()!!)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()

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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}