import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readInt()
    val nums = LongArray(n){br.readInt().toLong()}
    if(n == 1){
        sb.append("1 1\n0\n1 1\n0\n1 1\n").append(-nums[0])
    } else {
        sb.append("1 ").append(n - 1).append('\n')
        for(x in 0 until n - 1){
            val mod = nums[x]%n
            nums[x] += mod * (n - 1)
            sb.append(mod * (n - 1)).append(' ')
        }
        sb.append('\n').append(n).append(' ').append(n).append('\n').append(-nums.last()).append('\n')
        nums[n - 1] = 0L
        sb.append("1 ").append(n).append('\n')
        for(x in 0 until n){
            sb.append(-nums[x]).append(' ')
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