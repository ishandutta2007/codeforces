fun main(){
    readLine()
    var ans = 0
    var x = 0
    for(c in readLine()!!)
        if(c != 'x'){
            ans += maxOf(0, x - 2)
            x = 0
        }
        else x += 1
    print(ans + maxOf(0, x - 2))
}