
import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numNodes = br.readLine().toInt()
    val connections = Array(numNodes){
        emptyList<Int>().toMutableList()
    }
    var splitFound = false
    var splitNode = -1

    val edges = Array(numNodes - 1){
        val (start, end) = br.readLine().split(' ').map{it.toInt() - 1}
        connections[start].add(it)
        connections[end].add(it)
        if(!splitFound){
            if(connections[start].size > 2){
                splitFound = true
                splitNode = start
            } else if(connections[end].size > 2){
                splitFound = true
                splitNode = end
            }
        }
        Pair(start, end)
     }

    val specialID0 = if(splitFound) connections[splitNode][0] else -1
    val specialID1 = if(splitFound) connections[splitNode][1] else -1
    val specialID2 = if(splitFound) connections[splitNode][2] else -1

    var regAssigned = if(splitFound) 3 else 0

    for(x in edges.indices){
        val toPrint = when(x){
            specialID0 -> 0
            specialID1 -> 1
            specialID2 -> 2
            else -> regAssigned++
        }
        sb.append(toPrint)
        sb.append('\n')
    }
    print(sb)


}