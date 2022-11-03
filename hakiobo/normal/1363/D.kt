import kotlin.system.exitProcess

fun main() {
    val br = System.`in`.bufferedReader()
    val numCases = br.readLine().toInt()
    repeat(numCases){
        val (n, k) = br.readLine().split(' ').map(String::toInt)
        val sets = Array(k){
            br.readLine().split(' ').drop(1).map(String::toInt)
        }
        var minBucket = 0
        var maxBucket = k - 1
        var mid = (minBucket + maxBucket) shr 1
        val initQuery = StringBuilder()
        var initSize = 0
        for(x in 0 until k){
            for(idx in sets[x]){
                initSize++
                initQuery.append(idx).append(' ')
            }
        }
        println("? $initSize $initQuery")
        val maxVal = br.readLine().toInt()

        while(minBucket != maxBucket){
            val query = StringBuilder()
            var qSize = 0
            for(x in minBucket..mid){
                for(idx in sets[x]){
                    qSize++
                    query.append(idx).append(' ')
                }
            }
            println("? $qSize $query")
            val num = br.readLine().toInt()
            if(num == maxVal){
                maxBucket = mid
            } else {
                minBucket = mid + 1
            }
            mid = (minBucket + maxBucket) shr 1
        }
        val finalQuery = StringBuilder("? ").append(n - sets[mid].size).append(' ')
        val notInFinalQuery = BooleanArray(n + 1)
        for(idk in sets[mid]){
            notInFinalQuery[idk] = true
        }
        for(x in 1..n){
            if(!notInFinalQuery[x]){
                finalQuery.append(x).append(' ')
            }
        }
        println(finalQuery)
        val otherVal = br.readLine().toInt()
        val regVal = otherVal.coerceAtLeast(maxVal)
        val password = StringBuilder("! ")
        for(x in 0 until k){
            if(x == mid){
                password.append(otherVal).append(' ')
            } else {
                password.append(regVal).append(' ')
            }
        }
        println(password)
        val feedback = br.readLine()
        if(feedback != "Correct"){
            exitProcess(-1)
        }
    }
}