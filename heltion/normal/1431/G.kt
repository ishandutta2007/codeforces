import java.util.*
import kotlin.math.abs
import kotlin.math.max

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    val (n, k) = readInts()
    val a = readInts().sorted()
    val dp = Array(n + 1){IntArray(k + 1)}
    for(i in 0 until n)
        for(j in 0 .. k){
            //println("$i $j ${dp[i][j]}")
            var sum = 0
            var haf = 0
            for(x in 0..k - j){
                if(x == 0) dp[i + 1][j + x] = maxOf(dp[i + 1][j + x],dp[i][j] + sum - 2 * haf)
                else dp[i + 2 * x][j + x] = maxOf(dp[i + 2 * x][j + x],dp[i][j] + sum - 2 * haf)
                if(i + 2 * (x + 1) > n) break
                haf += a[i + x]
                sum += a[i + 2 * x + 1] + a[i + 2 * x]
            }
        }
    println(dp[n][k])
}