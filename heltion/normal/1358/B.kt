fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map(String::toInt).sorted()
        var ans = 1
        var per = 1
        for(i in 0 until n){
            if(per >= a[i])
                ans = maxOf(ans, per + 1)
            per += 1
        }
        println(ans)
    }
}