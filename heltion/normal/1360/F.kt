fun main(){
    repeat(readLine()!!.toInt()){
        val (n, m) = readLine()!!.split(' ').map(String::toInt)
        val s = Array(n){readLine()!!}
        val mask = Array(m){Array(26){0}}
        for(i in 0 until m)
            for(j in 0 until n)
                for(k in 0 until 26)
                    if(s[j][i] != 'a' + k)
                        mask[i][k] = mask[i][k] or (1 shl j)
        val dp = Array(m + 1){Array(1 shl n){-1}}
        dp[m][0] = 0
        for(i in m - 1 downTo 0)
            for(j in 0 until (1 shl n))
                for(k in 0 until 26)
                    if(((j and mask[i][k]) == mask[i][k]) && (dp[i + 1][j xor mask[i][k]] != -1))
                        dp[i][j] = k
        var x = -1
        for(j in 0 until (1 shl n)) if(dp[0][j] != -1) x = j
        if(x == -1) println(-1)
        else{
            for(i in 0 until m){
                print('a' + dp[i][x])
                x = x xor mask[i][dp[i][x]]
            }
            println()
        }
    }
}