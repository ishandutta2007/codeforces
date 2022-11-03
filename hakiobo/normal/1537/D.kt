import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
//    val limit = 31_662
//    val sieve = IntArray(limit + 1)
//    val primes = mutableListOf<Int>()
//    for (x in 2..limit) {
//        if (sieve[x] == 0) {
//            primes += x
//            sieve[x] = x
//            var i = x * x
//            while (i <= limit) {
//                sieve[i] = x
//                i += x
//            }
//        }
//    }
//    val win = BooleanArray()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        if(n and 1 == 1){
            sb.appendLine("Bob")
        } else {
            var pow = 0
            while ((1 shl pow) < n){
                pow++
            }
            if((1 shl pow) == n){
                if(pow and 1 == 1){
                    sb.appendLine("Bob")
                } else {
                    sb.appendLine("Alice")
                }
            } else {
                sb.appendLine("Alice")
            }
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