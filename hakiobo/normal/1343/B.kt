fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val n = br.readLine().toInt()
        if (n and 3 == 0){
            sb.append("YES\n")
            val a = IntArray(n){ idx ->
                if(idx < (n shr 1)){
                    (idx + 1) shl 1
                } else {
                    if(idx and 1 == 0){
                        1 + idx - (n shr 1)
                    } else {
                        n + 2 - idx + (n shr 1)
                    }
                }
            }
            sb.append(a.joinToString(" ")).append('\n')
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}