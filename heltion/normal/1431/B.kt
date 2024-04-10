fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    repeat(readInt()){
        val s = readLine()!!
        var L = 1
        var ans = 0
        for(c in s){
            if(c == 'w'){
                ans += 1
                L = 1
            }
            else{
                if(L == 1){
                    L = 0
                }
                else{
                    ans += 1
                    L = 1
                }
            }
        }
        println(ans)
    }
}