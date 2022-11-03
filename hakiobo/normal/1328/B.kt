fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (n, k1) = br.readLine().split(' ').map(String::toInt)
        val k = k1.toLong()
        var c = 0L
        var i = 0
        while (c < k) {
            i++
            c += i
        }
        val firstB = n - 1 - i
        val secondB = firstB + ((c - k).toInt()) + 1
        repeat(firstB){
            sb.append('a')
        }
        sb.append('b')
        repeat(secondB - firstB - 1){
            sb.append('a')
        }
        sb.append('b')
        repeat(n - 1 - secondB){
            sb.append('a')
        }
        sb.append('\n')
    }
    print(sb)
}