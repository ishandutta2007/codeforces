import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val a = IntArray(n) { br.readInt() }
    val b = IntArray(m) { br.readInt() }
    var ways = 1L
    var hasVal = false
    var mark = -1
    val mod = 998244353L
    var bPtr = m - 1
    var aPtr = n - 1
    while (aPtr >= 0 && bPtr >= 0) {
        if (a[aPtr] < b[bPtr]) {
            if (!hasVal) {
                ways = 0L
            } else {
                ways *= (mark - aPtr)
                ways %= mod
                hasVal = false
                mark = aPtr
            }
            bPtr--
        } else {
            if (!hasVal && a[aPtr] == b[bPtr]) {
                mark = aPtr
                hasVal = true
            }
            aPtr--
        }
    }
    if(bPtr != 0 || !hasVal) ways = 0L
    print(ways)
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
    while (read <= SPACE_INT && read != -1) {
        mark(1)
        read = read()
        if (read == NL_INT) {
            read = -1
            break
        }
    }
    if (read != -1) {
        reset()
    }
    return if (neg) -ret else ret
}