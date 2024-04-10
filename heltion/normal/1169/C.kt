import kotlin.system.exitProcess

fun main() {
    var s = readLine()!!.split(' ').map{it.toInt()}
    var (n, m) = s
    var a = readLine()!!.split(' ').map{it.toInt()}
    var L = 0; var R = m
    while(L < R){
        var M = (L + R) / 2;
        var ok = true
        var Last = 0
        for(x in a){
            if(x <= Last){
                if(x + M < Last) {
                    ok = false
                    break
                }
            }
            else if(Last + m - x > M) Last = x
            if(!ok) break
        }
        if(ok) R = M;
        else L = M + 1;
    }
    print(L)
}