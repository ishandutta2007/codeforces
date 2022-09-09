fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val n = readInt()
        val ans = mutableListOf<Int>()
        val ab = Array(n){
            val (a, b) = readInts()
            ans.add(a)
            ans.add(b)
            ans.add(a - 1)
            ans.add(b + 1)
            Pair(a, b)
        }
        var anss = -1
        for(x in ans) if(ab.count{it.first <= x && x <= it.second} == 1) anss = x
        println(anss)
    }
}