import kotlin.system.exitProcess

fun main(){
    var s = readLine()!!.split(' ')
    var p = s[0].toInt()
    var y = s[1].toInt()
    for(x in y downTo p + 1) {
        var ok = true
        for(i in 2..p){
            if(x % i == 0){
                ok = false
                break
            }
            if(i * i >= x) break
        }
        if(ok){
            print(x)
            exitProcess(0)
        }
    }
    print(-1)
}