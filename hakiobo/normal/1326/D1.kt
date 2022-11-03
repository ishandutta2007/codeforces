import java.lang.System.`in`


fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val s = br.readLine()
        var id = 0
        while (2 * id <= s.length - 2 && s[id] == s[s.lastIndex - id]) {
            id++
        }
        if (s.length / 2 == id) {
            sb.append(s)
        } else {
            val middleLength = s.length - 2 * id
            val charsPrefix = CharArray(1 + 2 * middleLength) {
                when {
                    it < middleLength -> s[id + it]
                    it > middleLength -> s[id + 2 * middleLength - it]
                    else -> '#'
                }
            }
            val charsSuffix = CharArray(1 + 2 * middleLength) {
                when {
                    it < middleLength -> s[id + middleLength - it - 1]
                    it > middleLength -> s[id + it - middleLength - 1]
                    else -> '#'
                }
            }
            val startLength = genZArray(charsPrefix)
            val endLength = genZArray(charsSuffix)

            if (startLength >= endLength) {
                for (x in 0 until id + startLength) {
                    sb.append(s[x])
                }
                for (x in s.length - id..s.lastIndex){
                    sb.append(s[x])
                }
            } else {
                for(x in 0 until id){
                    sb.append(s[x])
                }
                for(x in s.length - id - endLength..s.lastIndex){
                    sb.append(s[x])
                }
            }
        }
        sb.append('\n')
    }
    print(sb)
}

private fun genZArray(s: CharArray): Int {
    val z = IntArray(s.size)
    var x = 0
    for (k in 1..z.lastIndex) {
        var size = if (x == 0) 0 else z[k - x]
        while (k + size < z.size && s[size] == s[k + size]) {
            size++
        }
        z[k] = size
        x = k
        if(k + size == z.size) return size
    }
    return -1
}