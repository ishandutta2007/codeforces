fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    val inf = 3000000L
    val n = readInt()
    val a = readLongs().toLongArray()
    var ans = 0L
    for(i in 30L downTo 1L){
        var pans = 0L
        var psum = 0L
        var msum = 0L
        for(j in 0 until n){
            if(a[j] > i) a[j] = - inf
            psum += a[j]
            pans = maxOf(psum - msum, pans)
            msum = minOf(psum, msum)
        }
        ans = maxOf(pans - i, ans)
    }
    print(ans)
}
//((n + 1)h + nc) / (2n + 1) = t
//(n + 1)h + nc = (2n + 1)t
//n(2t - h + c)= h - t