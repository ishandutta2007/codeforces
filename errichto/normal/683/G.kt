fun main(args: Array<String>) {
    var (one, two) = readLine()!!.split('(')
    var b : Long = 1L
    var tmp = ""
    for(i in 2..(one.length-1)) {
        b = b * 10L
        tmp = tmp + one[i]
    }
    if(tmp.length == 0) tmp = "0"
    var a : Long = tmp.toLong()
    tmp = ""
    var d : Long = 1L
    for(i in 0..(two.length-2)) {
        d = d * 10L
        tmp = tmp + two[i]
    }
    d = b * (d - 1L)
    if(tmp.length == 0) tmp = "0"
    var c : Long = tmp.toLong()
    a = a * d + b * c
    b = b * d
    var memo_a = a
    var memo_b = b
    while((a > 0) and (b > 0)) {
        a = a % b
        var pom = b
        b = a
        a = pom
    }
    print(memo_a / (a + b))
    print("/")
    print(memo_b / (a + b))
}