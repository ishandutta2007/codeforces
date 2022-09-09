fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    repeat(readInt()){
        val n = readInt()
        val a = readLongs().sorted().reversed()
        var ans = 0L
        repeat(n){
            ans = maxOf(ans, (it + 1) * a[it])
        }
        println(ans)
    }
}