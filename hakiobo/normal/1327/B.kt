import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val n = br.readLine().toInt()
        val lists = Array(n){
            br.readLine().split(' ').drop(1).map{it.toInt() - 1}
        }
        val assignedPrince = BooleanArray(n)
        val assignedPrincess = BooleanArray(n)
        repeat(n){
            for(prince in lists[it]){
                if(!assignedPrince[prince]){
                    assignedPrince[prince] = true
                    assignedPrincess[it] = true
                    break
                }
            }
        }
        var prince = -1
        var princess = -1
        repeat(n){
            if(!assignedPrince[it]){
                prince = it + 1
            }
            if(!assignedPrincess[it]){
                princess = it + 1
            }
        }
        if(prince == -1){
            sb.append("OPTIMAL\n")
        } else {
            sb.append("IMPROVE\n")
            sb.append(princess)
            sb.append(' ')
            sb.append(prince)
            sb.append('\n')
        }
    }
    print(sb)
}