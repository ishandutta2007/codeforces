fun main(){
    val mod = 1000000007;
    var (n, m) = readLine()!!.split(' ').map({it.toInt()})
    var A = Array(n + 2){IntArray(n + 2)}
    A[1][n] = 1
    repeat(m){
        for(i in 1..n)
            for(j in n downTo 1)
                if(j >= i)
                    A[i][j] = (A[i][j] + A[i][j + 1]) % mod
        for(i in 1..n)
            for(j in n downTo 1)
                if(j >= i)
                    A[i][j] = (A[i][j] + A[i - 1][j]) % mod
    }
    var ans = 0
    for(i in 1..n)
        for(j in 1..n)
            ans = (ans + A[i][j]) % mod
    println(ans)
}