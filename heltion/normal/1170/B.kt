import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()
fun main(){
    var m = 0
    var m2 = 0
    var n = rdi()
    var a = rdis()
    var ans = 0
    for(x in a){
        if(x < m && x < m2) ans += 1
        if(x >= m){
            m2 = m
            m = x
        }
        else if(x >= m2){
            m2 = x
        }
    }
    print(ans)
}