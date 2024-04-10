fun main(){
    fun readIntArray() = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    val (n, m) = readIntArray()
    val a = readIntArray()
    val f = {m : Int ->
        val s = IntArray(2 * n + 2)
        var shift = n + 1
        var ans = 0L
        var p = 0
        for(i in a.indices){
            p = shift
            while(p < s.size){
                s[p] += 1
                p += p and - p
            }
            if(a[i] >= m) shift -= 1
            else shift += 1
            p = shift
            while(p > 0){
                ans -= s[p]
                p -= p and -p
            }
            ans += i + 1
        }
        ans
    }
    println(f(m) - f(m + 1))
}