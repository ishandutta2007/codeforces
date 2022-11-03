fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases) {
        val (n, m) = br.readLine().split(' ').map(String::toInt)
        val monsters = IntArray(n)
        val connections = Array(n) {
            emptyList<Pair<Int, Int>>().toMutableList()
        }
        repeat(m) {
            val (a, b, w) = br.readLine().split(' ').map(String::toInt)
            val u = a - 1
            val v = b - 1
            connections[u].add(Pair(v, w))
            connections[v].add(Pair(u, w))
        }
        var valid = true
        for(node in 0 until n){
            var maxW = 0
            for(connection in connections[node]){
                maxW = maxW.coerceAtLeast(connection.second)
            }
            monsters[node] = maxW
        }
        for(node in 0 until n){
            val w = monsters[node]
            for(connection in connections[node]){
                if(connection.second != w.coerceAtMost(monsters[connection.first])){
                    valid = false
                }
            }
        }
        if(valid){
            sb.append("YES\n")
            for(m in monsters){
                sb.append(m).append(' ')
            }
            sb.append('\n')
        } else {
            sb.append("NO\n")
        }
    }
    print(sb)
}