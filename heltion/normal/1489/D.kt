import kotlin.system.exitProcess

fun main() {
    val s = Array(readLine()!!.toInt()){readLine()!!}.sortedBy{it.length}
    for(i in 1 until s.size) if(!s[i].contains(s[i - 1])){
        print("NO")
        exitProcess(0)
    }
    println("YES")
    for(c in s) println(c)
}