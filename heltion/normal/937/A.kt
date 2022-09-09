fun main(){
    var n = readLine()!!.toInt()
    var s = readLine()!!.split(' ')
    var A = mutableListOf<Int>()
    for(x in s) A.add(x.toInt())
    A.sort()
    var ans = 0
    var m = 0
    for(a in A){
        if(a != m) ans += 1
        m = a
    }
    println(ans)
}