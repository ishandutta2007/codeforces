fun main(){
    var n = readLine()!!.toInt()
    var s = readLine()
    var ms = mutableSetOf<Char>()
    for(c in s!!) ms.add(c)
    if((n == 1) or (ms.size < s.length)) print("Yes")
    else print("No")
}