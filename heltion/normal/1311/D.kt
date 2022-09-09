import java.lang.Math.abs

fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readIntArray() = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    repeat(readInt()){
        val (a, b, c) = readIntArray()
        var (ans, aa, bb, cc) = IntArray(4){30000}
        for(i in 1..20000)
            for(j in i..20000 step i)
                for(k in j..20000 step j) {
                    val pans = abs(a - i) + abs(b - j) + abs(c - k)
                    if(pans < ans){
                        ans = pans
                        aa = i
                        bb = j
                        cc = k
                    }
                }
        println(ans)
        println("$aa $bb $cc")
    }
}