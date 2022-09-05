fun main(args: Array<String>) {
    val (q) = readLine()!!.split(' ').map(String::toInt)
    for(rep in 0..(q-1)) {
        val (n,m,p) = readLine()!!.split(' ').map(String::toInt)
        var ok = 0
        for(i in 1..n) for(j in 1..m) if(i*j == p) ok = 1
        if(ok == 1) println("Yes")
        else println("No")
    }
}