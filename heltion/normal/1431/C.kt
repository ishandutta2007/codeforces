fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    repeat(readInt()){
        val (n, k) = readInts()
        val p = readInts()
        val s = mutableListOf<Int>()
        for(c in p){
            if(s.isEmpty()) s.add(c)
            else s.add(c + s.last())
        }
        var ans = 0
        for(i in 1..n){
            if(i * k > n) break
            val L = n - i * k
            val R = L + i - 1
            var pans = s[R]
            if(L > 0) pans -= s[L - 1]
            ans = maxOf(ans, pans)
        }
        println(ans)
    }
}