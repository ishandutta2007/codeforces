import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val cache = IntArray(n)
    fun query(num: Int): Int {
        if(cache[num - 1] == 0 ){
            println("? $num")
            cache[num - 1] = br.readInt()
        }
        return cache[num - 1]

    }

    var low = 1
    var high = n
    var mid = (high + low) / 2
    while (low < high){
        val a = query(mid)
        val b = query(mid + 1)
        if(a < b){
            high = mid
        } else {
            low = mid + 1
        }
        mid = (high + low) / 2
    }
    print("! $mid")


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