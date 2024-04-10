import java.util.*
import kotlin.math.abs

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    val (n, k, x) = readInts()
    val a = readLongs()
    var L = 0L
    var R = 10000000000L
    while(L < R){
        val M = (L + R) / 2
        val pq = PriorityQueue<Long>()
        var sum = 0L
        var rm = 0
        repeat(n){ i ->
            pq.add(-a[i])
            sum += a[i]
            if(sum > M) {
                sum += pq.poll()
                rm += 1
            }
            if(pq.size == x){
                pq.clear()
                sum = 0
            }
        }
        if(rm > k) L = M + 1
        else R = M
    }
    println(L)
}