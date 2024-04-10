fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    repeat(readInt()){
        val n = readInt()
        val a = readInts().withIndex().sortedBy{it.value}
        var s = 0
        var k = 0
        for(i in 0 until n){
            s += a[i].value
            if(s >= n) break
            k = i + 1
        }
        var j = k
        for(i in 0 until k){
            repeat(if(i == 0) a[i].value else a[i].value - 1) {
                print("${a[j].index + 1} ")
                j += 1
            }
            print("${a[i].index + 1} ")
        }
        while(j < n){
            print("${a[j].index + 1} ")
            j += 1
        }
        println()
    }
}