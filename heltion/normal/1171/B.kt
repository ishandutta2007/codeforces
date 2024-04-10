import kotlin.math.min

fun main(){
    var s = readLine()!!.split(' ')
    var y = s[0].toInt()
    var r = s[1].toInt()
    var b = s[2].toInt()
    println(min(min(y, r - 1), b - 2) * 3 + 3)
}