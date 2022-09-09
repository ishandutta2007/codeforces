fun main(){
    repeat(readLine()!!.toInt()){
        val (n, x, y) = readLine()!!.split(' ').map { it.toInt() }
        var ans = Int.MAX_VALUE
        fun get(x : Int, l : Int, r : Int) : Int{
            if(x <= l) return r - x
            if(x >= r) return x - l
            return r - l + minOf(x - l, r - x)
        }
        for (i in 1 until n){
            ans = minOf(ans, maxOf(get(x, 1, i), get(y, i + 1, n)))
            ans = minOf(ans, maxOf(get(y, 1, i), get(x, i + 1, n)))
        }
        println(ans)
    }
}