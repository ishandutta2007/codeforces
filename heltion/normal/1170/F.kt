import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toLong()}.toMutableList()

fun main(){
    var (n, m, k) = rdis()
    var a = rdis()
    a.add(0)
    a.sort()
    var s = Array(n.toInt() + 1){0L}
    for(i in 1..n.toInt())
        s[i] = s[i - 1] + a[i]
    var ans = 1000000000000000000L
    var Last = 1
    for(i in 1..(n - m).toInt() + 1){
        var L = maxOf(i, Last)
        var R = i + m.toInt() / 2
        while(L < R){
            var M = (L + R + 1) / 2
            var nee = (M - i + 1) * a[M] - (s[M] - s[i - 1])
            if(nee <= k) L = M
            else R = M - 1
        }
        var j = L
        Last = L
        if(j == i + m.toInt() / 2){
            var pans = (j - i + 1) * a[j] - (s[j] - s[i - 1])
            pans += (s[i + m.toInt() - 1] - s[j]) - (i + m - 1 - j) * a[j]
            ans = minOf(ans, pans)
        }
        else{
            var l = a[j]
            var r = a[j + 1]
            while(l < r){
                var M = (l + r + 1) / 2
                var nee = (j - i + 1) * M - (s[j] - s[i - 1])
                if(nee <= k) l = M
                else r = M - 1
            }
            var pans = (j - i + 1) * l - (s[j] - s[i - 1])
            pans += (s[i + m.toInt() - 1] - s[j]) - (i + m - 1 - j) * l
            ans = minOf(ans, pans)
        }
    }
    print(ans)
}