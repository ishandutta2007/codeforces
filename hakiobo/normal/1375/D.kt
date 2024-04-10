import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val moves = mutableListOf<Int>()
        val counts = IntArray(n + 1)

        val nums = IntArray(n) {
            val num = br.readInt()
            counts[num]++
            num
        }
        var mex = 0
        while (counts[mex] != 0){
            mex++
        }
        fun doMove(idx: Int){
            moves.add(idx + 1)
            val tmp = nums[idx]
            nums[idx] = mex
            counts[tmp]--
            counts[mex]++
            if(tmp < mex && counts[tmp] == 0){
                mex = tmp
            }
            while (counts[mex] != 0){
                mex++
            }
        }
        var goodCtr = 0
        for(x in goodCtr until n){
            if(nums[x] == x){
                goodCtr++
            } else {
                break
            }
        }
        while (goodCtr != n){
            while (mex != n){
                doMove(mex)
            }
            for(x in goodCtr until n){
                if(nums[x] == x){
                    goodCtr++
                } else {
                    break
                }
            }
            for(x in goodCtr until n){
                if(nums[x] == goodCtr){
                    doMove(x)
                    break
                }
            }
        }
        sb.append(moves.size).append('\n')
        sb.append(moves.joinToString(" ")).append('\n')
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