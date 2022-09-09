fun main(){
    repeat(readLine()!!.toInt()){
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        var d = 1
        var i = 1
        while(i * i <= n){
            if(n % i == 0){
                if(i <= k) d = maxOf(d, i);
                if(n / i <= k) d = maxOf(d, n / i);
            }
            i += 1
        }
        println(n / d)
    }
}