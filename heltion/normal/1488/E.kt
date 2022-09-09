import java.util.*

fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val bit = IntArray(n)
        fun update(x : Int, v : Int){
            var i = x + 1
            while(i <= n){
                bit[i - 1] = maxOf(bit[i - 1], v)
                i += i and -i
            }
        }
        fun query(x : Int) : Int{
            var res = 0
            var i = x + 1
            while(i > 0){
                res = maxOf(bit[i - 1], res)
                i -= i and -i
            }
            return res
        }
        val pos = TreeMap<Int, Int>()
        var ans = 1
        for(i in a.indices.reversed()){
            if(pos.containsKey(a[i])){
                var x = query(pos[a[i]]!! - 1) + 2
                ans = maxOf(ans, x)
                update(pos[a[i]]!!, x)
                update(i, 1)
            }
            else{
                pos[a[i]] = i
                update(i, 1)
            }
        }
        println(ans)
    }
}