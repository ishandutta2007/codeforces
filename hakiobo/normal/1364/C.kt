import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val a = IntArray(n) { br.readInt() }
    val b = IntArray(n) { -1 }
    var ptr = 0
    var prev = 0
    for (i in 0 until n) {
        val num = a[i]
        if (prev < num) {
            b[i] = prev
            prev++
            while (prev < num) {
                while (b[ptr] != -1) {
                    ptr++
                }
                b[ptr] = prev
                prev++
            }
        }
        prev = num
    }
    while (ptr < n) {
        if (b[ptr] == -1) {
            b[ptr] = prev + 1
        }
        ptr++
    }
    print(b.joinToString(" "))
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