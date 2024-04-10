fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        var (n, m, x, y) = readInts()
        y = minOf(x * 2, y)
        var ans = 0
        repeat(n){
            val s = readLine()!!
            var j = -1
            for(i in 0 until m){
                if(i == j) continue
                if(s[i] == '*') continue
                if(i + 1 < m && s[i + 1] == '.'){
                    ans += y
                    j = i + 1
                }
                else ans += x
            }
        }
        println(ans)
    }
}