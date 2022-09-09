import java.lang.StringBuilder

fun main(){
    repeat(readLine()!!.toInt()){
        var (n, k) = readLine()!!.split(' ').map(String::toLong)
        val s = readLine()!!
        var ones = 0L
        var zeros = 0L
        var end = false
        val stringBuilder = StringBuilder(n.toInt())
        for(c in s){
            if(end) stringBuilder.append(c)
            else if(c == '1') ones += 1L
            else{
                if(k >= ones){
                    zeros += 1
                    k -= ones
                }
                else{
                    end = true
                    repeat(zeros.toInt()){stringBuilder.append('0')}
                    repeat((ones - k).toInt()){stringBuilder.append('1')}
                    stringBuilder.append('0')
                    repeat(k.toInt()){stringBuilder.append('1')}
                }
            }
        }
        if(!end){
            repeat(zeros.toInt()){stringBuilder.append('0')}
            repeat(ones.toInt()){stringBuilder.append('1')}
        }
        println(stringBuilder)
    }
}