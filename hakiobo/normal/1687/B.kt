import java.io.BufferedReader

fun main() {

    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val queryArray = CharArray(m)
    fun query(): Int {
        println("? ${queryArray.joinToString("")}")
        return readLine()!!.toInt()
    }
    queryArray.fill('0')
    val lengths = IntArray(m)
    for (i in 0 until m) {
        queryArray[i] = '1'
        lengths[i] = query()
        queryArray[i] = '0'
    }
    queryArray.fill('1')
    val sorted = (0 until m).sortedByDescending { lengths[it] }
    var prev = query()
    var ans = 0
    for (i in 0 until m - 1) {
        queryArray[sorted[i]] = '0'
        val new = query()
        if (prev - new == lengths[sorted[i]]) {
            ans += lengths[sorted[i]]
        }
        prev = new
    }
    ans += prev
    println("! $ans")
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