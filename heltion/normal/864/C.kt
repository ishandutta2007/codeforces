import kotlin.system.exitProcess

fun main(){
    var s = readLine()!!.split(' ').map{it.toInt()}
    var a = s[0]
    var b = s[1]
    var f = s[2]
    var k = s[3]
    var g = b
    var ans = 0
    for(i in 1..k){
        if(i % 2 == 1){
            if(g < f){
                print(-1)
                exitProcess(0)
            }
            g -= f
            if(g < a - f){
                ans += 1
                g = b
            }
            if(g < a - f){
                print(-1)
                exitProcess(0)
            }
            if(i == k)break
            if(g < 2 * (a - f)){
                ans += 1
                g = b
            }
            g -= a - f
        }
        else{
            if(g < a - f){
                print(-1)
                exitProcess(0)
            }
            g -= a - f
            if(g < f){
                ans += 1
                g = b
            }
            if(g < f){
                print(-1)
                exitProcess(0)
            }
            if(i == k)break
            if(g < 2 * f){
                ans += 1
                g = b
            }
            g -= f
        }
    }
    print(ans)
}