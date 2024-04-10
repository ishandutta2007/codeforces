fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val (n, k1, k2) = readInts()
        val s = readLine()!!
        var ans = 0
        var L = 0
        var R = 0
        while(L < n){
            if(s[L] == '1'){
                while(R < n && s[R] == '1') R += 1
                var p = 0
                repeat(R - L){
                    p = minOf(k2 - p, k1)
                    ans += p
                }
            }
            R += 1
            L = R
        }
        println(ans)
    }
}