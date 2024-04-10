fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val size = br.readLine().toInt()
        val figures = br.readLine().split(' ').map(String::toInt)
        var adjDif = false
        var adjSame = false
        var prev = figures.last()
        figures.forEach {
            if (prev == it)  adjSame = true  else  adjDif = true 
            prev = it
        }
        if (!adjDif) {
            sb.append(1)
            sb.append('\n')
            repeat(size) {
                sb.append(1)
                sb.append(' ')
            }
        } else if (size and 1 == 0) {
            sb.append(2)
            sb.append('\n')
            repeat(size) { id ->
                sb.append(1 + id % 2)
                sb.append(' ')
            }
        } else if (adjSame) {
            sb.append(2)
            sb.append('\n')
            prev = figures.last()
            var foundMatch = false
            var print = 1
            figures.forEach{
                if(!foundMatch && it == prev){
                    foundMatch = true
                } else {
                    print = 3 - print
                }
                sb.append(print)
                sb.append(' ')
                prev = it
            }
        } else {
            sb.append(3)
            sb.append('\n')
            repeat(size - 1){
                sb.append(1 + it%2)
                sb.append(' ')
            }
            sb.append(3)
        }
        sb.append('\n')
    }
    print(sb)
}