import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t){
        val n = br.readInt()
        var numOdd = 0
        var numEven = 0
        val nums = IntArray(2*n){
            val num = br.readInt()
            if(1 and num == 0) numEven++ else numOdd++
            num
        }
        if(numEven and 1 == 1){
            numEven--
            numOdd--
        } else if(numEven > 0){
            numEven -= 2
        } else {
            numOdd -= 2
        }
        var ptr = 0
        while (numOdd > 0){
            while (nums[ptr] and 1 == 0){
                ptr++
            }
            numOdd--
            sb.append(++ptr).append(' ')
            while (nums[ptr] and 1 == 0){
                ptr++
            }
            numOdd--
            sb.append(++ptr).append('\n')
        }
        ptr = 0
        while (numEven > 0){
            while (nums[ptr] and 1 == 1){
                ptr++
            }
            numEven--
            sb.append(++ptr).append(' ')
            while (nums[ptr] and 1 == 1){
                ptr++
            }
            numEven--
            sb.append(++ptr).append('\n')
        }
    }
    print(sb)
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