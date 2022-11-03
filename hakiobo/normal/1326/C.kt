
import java.lang.System.`in`

private const val MOD = 998244353L

fun main() {
    val br = `in`.bufferedReader()
    val (n, numParts) = br.readLine().split(' ').map(String::toLong)
    val permutation = br.readLine().split(' ').map(String::toLong)
    val maxVal = (n * (n + 1)) / 2 - ((n - numParts) * (n - numParts + 1)) / 2
    val cutOff = n - numParts
    var numInBetween = 0
    var partsFound = 1L
    var foundFirst = false
    permutation.forEach {
        if (it > cutOff) {
            if (foundFirst) {
                partsFound *= (numInBetween + 1)
                partsFound %= MOD
            }
            numInBetween = 0
            foundFirst = true
        } else {
            numInBetween++
        }
    }
    print(String.format("%d %d", maxVal, partsFound))
}