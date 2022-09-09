import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()

fun main(){
    var (n, m) = rdis()
    var a = rdis()
    var s = Array(n + 1){0}
    for(i in a.indices) s[i + 1] = s[i] + a[i]
    var q = rdi()
    repeat(q){
        var c = rdis()
        var last = 1
        var wuse = 1
        for(i in 1..c[0]){
            var L = wuse - 1
            var R = n
            while(L < R){
                var M = (L + R + 1) / 2
                if(c[i] - last >= s[M] - s[wuse - 1]) L = M;
                else R = M - 1
            }
            last = c[i] + 1
            wuse = L + 1
        }
        if(s[n] - s[wuse - 1] <= m - c[c[0]]) println("YES")
        else println("NO")
    }
}