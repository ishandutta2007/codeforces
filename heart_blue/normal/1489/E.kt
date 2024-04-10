import java.util.*
import kotlin.Comparator

fun main() {
    val N: Int = (2e5 + 10).toInt()
    var q = readLine()!!.toInt()
    var lans = Array<Int>(N, { it -> 0 })
    var rans = Array<Int>(N, { it -> 0 })
    var lcnt = 0
    var rcnt = 0
    for (ks in 1..q) {
        var str = readLine()!!
        var x = str.substring(2).toInt()
        var op = str[0]
        if(op == 'L') {
            lcnt++
            lans[x] = -lcnt
            rans[x] = lcnt - 1
        } else if (op == 'R')
        {
            rcnt++
            rans[x] = -rcnt
            lans[x] = rcnt - 1
        } else {
            println(Math.min(lans[x]+lcnt,rans[x]+rcnt))
        }
    }
}