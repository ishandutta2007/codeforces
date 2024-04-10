fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val length = br.readLine().toInt()
        val num = br.readLine()
        val a = CharArray(length)
        val b = CharArray(length)
        var dif = false
        num.forEachIndexed{id, c ->
            when(c){
                '2' -> {
                    if(dif){
                        a[id] = '0'
                        b[id] = '2'
                    } else {
                        a[id] = '1'
                        b[id] = '1'
                    }
                }
                '1' -> {
                    if(dif){
                        a[id] = '0'
                        b[id] = '1'
                    } else {
                        a[id] = '1'
                        b[id] = '0'
                        dif = true
                    }
                }
                '0' -> {
                    a[id] = '0'
                    b[id] = '0'
                }
            }
        }
        a.forEach { sb.append(it) }
        sb.append('\n')
        b.forEach { sb.append(it) }
        sb.append('\n')
    }
    print(sb)
}