import java.lang.Math.max

fun main(){
    var T = readLine()!!.toInt()
    for(i in 0 until T){
        var n = readLine()!!.toInt()
        var A : MutableList<Triple<Int, Int, Int>> = mutableListOf()
        for(j in 0 until n){
            var s = readLine()!!.split(' ')
            var l = s[0].toInt()
            var r = s[1].toInt()
            A.add(Triple(l, r, j))
        }
        A.sortWith(compareBy({it.first}, {it.second}))
        var ans = arrayOfNulls<Int>(n)
        var m = A[0].second
        var ok = false
        for(j in 1 until A.size){
            if(m < A[j].first){
                for(k in 0 until n) if(k < j) ans[A[k].third] = 2
                else ans[A[k].third] = 1
                ok = true
                break
            }
            m = max(m, A[j].second)
        }
        if(ok == false) println(-1)
        else{
            for(i in 0 until n) print("${ans[i]} ")
            println("")
        }
    }
}