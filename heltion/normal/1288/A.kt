fun main(){
    repeat(readLine()!!.toInt()){
        var (n, d) = readLine()!!.split(' ').map({it.toInt()})
        var ok = false
        var x = 0;
        while(x * x <= d){
            if(x + (d + x) / (x + 1) <= n) ok = true
            x += 1
        }
        println(if(ok) "YES" else "NO")
    }
}