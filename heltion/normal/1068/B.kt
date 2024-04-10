fun main(){
    var b = readLine()!!.toLong()
    var ans = 0
    for(i : Long in 1..b){
        if(i * i > b) break
        if(b % i == 0L){
            ans += 1
            if(i * i != b) ans += 1
        }
    }
    print(ans)
}