import kotlin.system.exitProcess

fun main() {
    var s = readLine()!!.split(' ').map{it.toInt()}
    var (n, a, x, b, y) = s;
    while(true){
        if(a == b){
            print("YES")
            exitProcess(0)
        }
        if(a == x || b == y) break
        if(a == n) a = 1
        else a = a + 1
        if(b == 1) b = n
        else b = b - 1
    }
    print("NO")
}