import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val letter = IntArray(26) { it }
    val revLetter = IntArray(26) { it }
    val name = br.readLine()
    repeat(m) {
        val (a, b) = br.readLine().split(" ").map { it[0] - 'a' }
        val c = revLetter[a]
        val d = revLetter[b]
        letter[c] = b
        letter[d] = a
        revLetter[a] = d
        revLetter[b] = c
    }
    val sb = StringBuilder()
    for (x in name) {
        sb.append('a' + letter[x - 'a'])
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