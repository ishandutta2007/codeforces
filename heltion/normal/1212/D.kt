fun r(n : Long, k : Long) : Int = if(n % k != 0L) 0 else r(n / k, k) + 1
fun main() {
    readLine()
    var a = readLine()!!.split(' ').map{it.toLong()}.sortedBy {r(it,2) - r(it, 3)}
    for(x in a) print("$x ")
}