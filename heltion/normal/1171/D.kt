fun main(){
    var s = readLine()!!.split(' ')
    var x = s[0].toInt()
    var y = s[1].toInt()
    var z = s[2].toInt()
    s = readLine()!!.split(' ')
    var a = s[0].toInt()
    var b = s[1].toInt()
    var c = s[2].toInt()
    if((a >= x) and (a + b >= x + y) and  (a + b + c >= x + y + z)) print("YES")
    else print("NO")
}