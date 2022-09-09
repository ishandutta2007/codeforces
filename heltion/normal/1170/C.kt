import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()
fun main(){
    var k = rdi()
    repeat(k){
        var s = rd()
        var t = rd()
        var ok = true
        var j = 0
        for(i in t.indices) {
            if (j >= s.length) {
                ok = false
                break
            }
            if (t[i] == s[j]) {
                j += 1
                continue
            }
            if (t[i] == '-') {
                ok = false
                break
            }
            if (j + 1 >= s.length) {
                ok = false
                break
            }
            if (s[j + 1] == '-') {
                j += 2
                continue
            }
            ok = false
            break
        }
        if(ok && (j == s.length)) println("YES")
        else println("NO")
    }
}