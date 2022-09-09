import kotlin.system.exitProcess

fun gcd(a : Int, b : Int) : Int{
    return if(b == 0) a else gcd(b, a % b)
}
fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    val (k, n) = readInts()
    val p = readInts()
    val s = readInts()
    if(n == 2){
        println("YES")
        println("${s[0]} ${p[0]}")
        println("${s[1]} ${p[0]}")
        return
    }
    val checks = {
        a : Int, d : Int ->
        var q = -1
        var f = 0
        for(x in s) if(x < a || (x - a) % d != 0){
            if(q != -1) f = gcd(f, x - q)
            if(q == -1) q = x
        }
        if(q == -1){
            println("YES")
            println("$a $d")
            println("$a $d")
            exitProcess(0)
        }
        for(x in p) if(f % x == 0){
            println("YES")
            println("$a $d")
            println("$q $x")
            exitProcess(0)
        }
    }
    val check = {
        a : Int, b : Int ->
        val d = b - a
        for(x in p) if(d % x == 0) checks(a, x)
    }
    check(s[0], s[1])
    check(s[1], s[2])
    check(s[0], s[2])
    println("NO")
}