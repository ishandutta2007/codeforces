import java.io.BufferedReader

fun main() {
    val chars = "codeforces"
    val br = System.`in`.bufferedReader()
    val k = br.readLong()
    val counts = IntArray(10) { 1 }
    var prod = 1L
    var enough = prod >= k
    var m = 2L
    while (!enough){
        for(x in 0 until 10){
            counts[x]++
            prod /= m - 1
            prod *= m
            if(prod >= k){
                enough = true
                break
            }
        }
        m++
    }
    for(x in 0 until 10){
        print(chars[x].toString().repeat(counts[x]))
    }
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
private fun BufferedReader.readLong(): Long {
    var ret = read().toLong()
    while (ret <= SPACE_INT) {
        ret = read().toLong()
    }
    val neg = ret == '-'.toLong()
    if (neg) {
        ret = read().toLong()
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