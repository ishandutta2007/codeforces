fun main(){
    repeat(readLine()!!.toInt()){
        val (n, x) = readLine()!!.split(' ').map{it.toInt()}
        val s = readLine()!!
        val balance = s.count{it == '0'} - s.count{it == '1'}
        var pre = 0
        var ans = 0
        for(c in s) if(ans != -1){
            if(balance == 0){
                if(x == pre) ans = -1
            }
            else if((x - pre) % balance == 0){
                if((x - pre) / balance >= 0) ans += 1
            }
            pre += if(c == '0') 1 else - 1
        }
        println(ans)
    }
}