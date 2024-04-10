import java.lang.StringBuilder

fun main(){
    repeat(readLine()!!.toInt()){
        val (n, a, b) = readLine()!!.split(' ').map(String::toInt)
        val stringBuilder = StringBuilder(n)
        for(i in 0 until b) stringBuilder.append('a' + i)
        while(stringBuilder.length < a) stringBuilder.append('a')
        while(stringBuilder.length < n) stringBuilder.append(stringBuilder[stringBuilder.length - a])
        println(stringBuilder)
    }
}