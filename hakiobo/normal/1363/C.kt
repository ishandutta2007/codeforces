fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (numNodes, specialNode) = br.readLine().split(' ').map(String::toInt)
        var cntsToTarget = 0
        repeat(numNodes - 1) {
            val (a, b) = br.readLine().split(' ').map(String::toInt)
            if(a == specialNode || b == specialNode){
                cntsToTarget++
            }
        }
        if(cntsToTarget <= 1 || numNodes and 1 == 0){
            sb.append("Ayush\n")
        } else {
            sb.append("Ashish\n")
        }
    }
    print(sb)
}