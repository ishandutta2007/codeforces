import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb1 = StringBuilder()
    val sb2 = StringBuilder()
    val n = br.readInt()
    val sieve = IntArray(10_000_001)
    for (i in 3 until sieve.size step 2) {
        if (sieve[i] == 0) {
            sieve[i] = i
            if (i < 3162) {
                var ct = i * i
                while (ct < sieve.size) {
                    sieve[ct] = i
                    ct += (i shl 1)
                }
            }
        }
    }
    repeat(n) {
        var higher = br.readInt()

        var lower: Int
        if (higher and 1 == 0) {
            lower = 1
            while (higher and 1 == 0) {
                higher = higher shr 1
                lower = lower shl 1
            }
        } else {
            val p = sieve[higher]
            lower = 1
            while (higher % p == 0) {
                higher /= p
                lower *= p
            }
        }

        if (higher != 1) {
            sb1.append(lower).append(' ')
            sb2.append(higher).append(' ')
        } else {
            sb1.append(-1).append(' ')
            sb2.append(-1).append(' ')
        }
    }

    println(sb1)
    println(sb2)
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