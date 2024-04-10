fun check(a : String, b : String, c : String) : Boolean{
    for(i in a.indices)
        if(a[i] != c[i] && b[i] != c[i])
            return false
    return true
}

fun main(){
    repeat(readLine()!!.toInt()){
        println(if(check(readLine()!!, readLine()!!, readLine()!!)) "YES" else "NO")
    }
}