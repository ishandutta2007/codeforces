fun main(){
    var s = readLine()!!.split(' ')
    var k = s[0].toLong()
    var d = s[1].toLong()
    var t = s[2].toLong() * 2
    var T = (k + d - 1) / d * d
    var S = T + k
    var C = t / S
    if(k * 2 >= t - C * S) print(T * C + (t - C * S) * .5)
    else print(T * C + (t - C * S - k))
}