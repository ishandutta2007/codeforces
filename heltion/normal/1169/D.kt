import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    var s = readLine()!!
    var p0 = mutableListOf<Int>()
    var p1 = mutableListOf<Int>()
    var N = mutableListOf<Int>()
    repeat(s.length) {
        N.add(s.length)
    }
    for(i in s.indices){
        if(s[i] == '0') p0.add(i)
        else p1.add(i)
    }
    if(p0.size > 2)
        for(i in p0.indices)
            for(j in i + 1 until  p0.size){
                if(2 * p0[j] - p0[i] > p0[p0.size - 1]) break
                if(s[2 * p0[j] - p0[i]] == '0'){
                    N[p0[i]] = 2 * p0[j] - p0[i];
                    break
                }
            }
    if(p1.size > 2)
        for(i in p1.indices)
            for(j in i + 1 until  p1.size){
                if (2 * p1[j] - p1[i] > p1[p1.size - 1]) break
                if (s[2 * p1[j] - p1[i]] == '1') {
                    N[p1[i]] = 2 * p1[j] - p1[i];
                    break
                }
            }
    var R = s.length
    var ans : Long = 0
    for(i in s.length - 1 downTo 0){
        R = min(R, N[i])
        ans += s.length - R
    }
    print(ans)
}