fun main(){
    repeat(readLine()!!.toInt()){
        val s = readLine()!!
        val t = readLine()!!
        val next = Array(s.length){IntArray(26)}
        for(i in s.length - 1 downTo 0){
            if(i != s.lastIndex) next[i] = next[i + 1].clone()
            else for(j in 0 until 26) next[i][j] = s.length
            next[i][s[i] - 'a'] = i
        }
        var ans = 1
        var index = 0
        for(c in t){
            if(next[0][c - 'a'] == s.length){
                ans = -1
                break
            }
            if(if(index == s.length) true else next[index][c - 'a'] == s.length){
                index = 0
                ans += 1
            }
            index = next[index][c - 'a'] + 1
        }
        println(ans)
    }
}