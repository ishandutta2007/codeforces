fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun main(){
    val (n, m, d) = readInts()
    val c = readInts()
    val b = mutableListOf<Int>()
    for(i in 0 until m){
        if(i == 0) b.add(d)
        else b.add(b.last() + c[i - 1] - 1 + d)
    }
    if(b.last() + c.last() - 1 + d <= n) println("NO")
    else{
        for(i in m - 1 downTo 0){
            if(i == m - 1) b[i] = minOf(b[i], n + 1 - c[i])
            else b[i] = minOf(b[i], b[i + 1] - c[i])
        }
        val ans = IntArray(n)
        for(i in 0 until m)
            for(j in 0 until c[i])
                ans[b[i] + j - 1] = i + 1
        println("YES")
        for(x in ans) print("$x ")
    }
}