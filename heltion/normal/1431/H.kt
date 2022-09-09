import java.lang.reflect.Array

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map(String::toInt)
fun readLongs() = readLine()!!.split(' ').map(String::toLong)
fun main(){
    val (n, m, k) = readInts()
    val a = readLongs()
    val b = readLongs()
    val c = Array(n){readLongs()}
    val s = (a + b).distinct().sorted()
    val axs = IntArray(n)
    val bxs = IntArray(m)
    for(i in 0 until n)
        for(j in s.indices)
            if(a[i] <= s[j]){
                axs[i] = j
                break
            }
    for(i in 0 until m)
        for(j in s.indices)
            if(b[i] <= s[j]){
                bxs[i] = j
                break
            }
    val add = LongArray(s.size)
    for(i in 0 until n)
        for(j in 0 until m)
            add[maxOf(axs[i], bxs[j])] = maxOf(add[maxOf(axs[i], bxs[j])], c[i][j])
    var ans = 1000000000000L
    if(s.size == 1) ans = 0L
    for(i in 0 until s.size - 1) add[i + 1] = maxOf(add[i], add[i + 1])
    for(i in 0 until s.size - 1){
        var pans = 0L
        var cur = 0L
        for(j in 0 until s.size - 1){
            if(s[j + 1] > cur){
                var fadd = add[j]
                if(i <= j) fadd = maxOf(fadd, add[i] + k)
                val h = (s[j + 1] - cur + fadd - 1) / fadd
                pans += h
                cur += h * fadd
            }
        }
        ans = minOf(ans, pans)
    }
    println(ans)
}