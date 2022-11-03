
import java.lang.System.`in`
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val s = br.readLine().toCharArray()
        val size = s.size
        val lastID = s.lastIndex
        var l = 0
        while (l < size - 1 - l && s[l] == s[lastID - l]) {
            l++
        }

        val middleLength = size - 2 * l
        val charsPrefix = CharArray(1 + 2 * middleLength) {
            when {
                it < middleLength -> s[l + it]
                it > middleLength -> s[l + 2 * middleLength - it]
                else -> '#'
            }
        }
        val charsSuffix = CharArray(1 + 2 * middleLength) {
            when {
                it < middleLength -> s[l + middleLength - it - 1]
                it > middleLength -> s[l + it - middleLength - 1]
                else -> '#'
            }
        }
        val startLength = lastPrefix(charsPrefix)
        val endLength = lastPrefix(charsSuffix)

        if (startLength >= endLength) {
            for (x in 0 until l + startLength) {
                sb.append(s[x])
            }
            for (x in size - l..lastID) {
                sb.append(s[x])
            }
        } else {
            for (x in 0 until l) {
                sb.append(s[x])
            }
            for (x in size - l - endLength..lastID) {
                sb.append(s[x])
            }
        }
        sb.append('\n')
    }
    print(sb)
}

private fun lastPrefix(s: CharArray): Int {
    val z = IntArray(s.size)
    var x = 0
    var y = 0
    for (k in 1..z.lastIndex) {
        var size = max(0, min(z[k - x], y - k + 1))
        while (k + size < z.size && s[size] == s[k + size]) {
            x = k
            y = k + size
            size++
        }
        z[k] = size
        if (k + size == z.size) return size
    }
    return 0
//    val pref = IntArray(s.size)
//    var c = 0
//    for(x in 1..pref.lastIndex){
//        while(c != 0 && s[c] != s[x]){
//            c = pref[c - 1]
//        }
//        if(s[c] == s[c]){
//            c++
//        }
//        pref[x] = c
//    }
//    return c
}