
import java.util.*
import kotlin.Comparator


fun main() {
    var ncase = readLine()!!.toInt()
    for(ks in 1..ncase) {
        val A = readLine()!!.split(' ').map(String::toLong).toLongArray()
        var n = A[0]
        var a = A[1]
        var b = A[2]
        b = Math.min(a*2,b)
        println("${n/2*b+(n%2)*a}")
    }
}