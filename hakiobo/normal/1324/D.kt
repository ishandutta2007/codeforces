
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val numClasses = br.readLine().toInt()
    val teacherRatings = br.readLine().split(' ').map(String::toInt)
    val netRatings = br.readLine().split(' ').mapIndexed { id, it -> teacherRatings[id] - it.toInt() }.sorted()
    var numPairs = 0L
    for(rating in netRatings){
        val checkRating = -rating
        if(rating > checkRating){
            numPairs--
        }
        numPairs += numClasses - findLowestExceeding(netRatings, checkRating)
    }
    print(numPairs/2)
}

private fun findLowestExceeding(list: List<Int>, target: Int): Int{
    var low = 0
    var high = list.size
    var mid = (high + low)/2
    while(low != high){
        if(list[mid] > target){
            high = mid
        } else {
            low = mid + 1
        }
        mid = (high + low)/2
    }
    return mid
}