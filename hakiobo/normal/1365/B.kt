import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val n = br.readInt()
        var prevNum = 0
        var nonDecreasing = true
        repeat(n) {
            val num = br.readInt()
            if (num < prevNum) {
                nonDecreasing = false
            }
            prevNum = num
        }
        var hasType0 = false
        var hasType1 = false
        repeat(n) {
            val num = br.readInt()
            if(num == 1){
                hasType1 = true
            } else {
                hasType0 = true
            }
        }
        if(nonDecreasing || (hasType0 && hasType1)){
            sb.append("Yes\n")
        } else {
            sb.append("No\n")
        }
    }
    print(sb)
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