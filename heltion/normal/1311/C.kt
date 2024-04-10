fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readIntArray() = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    repeat(readInt()){
        readIntArray()
        val s = readLine()!!
        val p = readIntArray().map{it - 1}
        val sum = Array(s.length){IntArray(0)}
        for(i in s.indices){
            sum[i] = if(i > 0) sum[i - 1].clone() else IntArray(26)
            sum[i][s[i] - 'a'] += 1
        }
        val ans = IntArray(26)
        for(i in p)
            for(j in ans.indices)
                ans[j] += sum[i][j]
        for(i in ans.indices) ans[i] += sum.last()[i]
        for(x in ans) print("$x ")
        println()
    }
}