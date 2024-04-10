fun check(s : Array<String>) : Boolean{
    for(i in s.size - 2 downTo 0)
        for(j in s.size - 2 downTo 0)
            if(s[i][j] == '1' && s[i][j + 1] != '1' && s[i + 1][j] != '1')
                return false
    return true
}
fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val s = Array(n){readLine()!!}
        println(if(check(s))"YES" else "NO")
    }
}