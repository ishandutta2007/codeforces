fun printX(L : Long, m : Int){
    if(m == 0) return
    printX(L / 2, m - 1)
    print(L % 2)
}
fun main(){
    repeat(readLine()!!.toInt()){
        val (n, m) = readLine()!!.split(' ').map(String::toInt)
        val a = Array(n){
            var res = 0L
            for(c in readLine()!!)
                res = res * 2 + (c - '0')
            res
        }
        var L = 0L
        var R = (1L shl m) - 1
        var k = (R - n) / 2
        while(L < R){
            var M = (L + R + 1) / 2
            var X = M
            for(x in a) if(x < M) X -= 1
            if(X > k) R = M - 1
            else L = M
        }
        printX(L, m)
        println()
    }
}