import java.io.BufferedReader
import kotlin.math.absoluteValue

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        val s = br.readLine().toCharArray().sortedDescending()
        val m = br.readInt()
        val nums = IntArray(m) { br.readInt() }
        val letters = CharArray(m)
        val zeros = mutableListOf<Int>()
        var sPtr = 0
        var numsLeft = m
        while (numsLeft > 0){
            zeros.clear()
            for(i in nums.indices){
                if(nums[i] == 0){
                    numsLeft--
                    zeros.add(i)
                    nums[i] = -1
                }
            }
            var lettersFound = 1
            var letter = s[sPtr++]
            while (lettersFound < zeros.size){
                if(s[sPtr] == letter){
                    lettersFound++
                } else {
                    lettersFound = 1
                    letter = s[sPtr]
                }
                sPtr++
            }
            while (sPtr < s.size && s[sPtr] == letter){
                sPtr++
            }
            for(zIdx in zeros){
                letters[zIdx] = letter
            }
            for(x in nums.indices){
                for(z in zeros){
                    nums[x] -= (z - x).absoluteValue
                }
            }
        }
        sb.append(letters.joinToString("")).append('\n')
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