fun f(a : LongArray) : Long{
    var pans = 0L
    var sum = a.sum()
    for(i in 1 until a.size) pans += a[i] * i
    var ans = pans
    var psum = a[0]
    for(i in 1 until a.size){
        pans += psum - (sum - psum)
        ans = minOf(ans, pans)
        psum += a[i]
    }
    return ans
}
fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    val (n, m, q) = readInts()
    val a = Array(n){readLongs().toLongArray()}
    val r = a.map{it.sum()}.toLongArray()
    val c = LongArray(m){
        var sum = 0L
        for(i in 0 until n) sum += a[i][it]
        sum
    }
    print("${f(r) + f(c)} ")
    repeat(q){
        var (x, y, z) = readInts()
        x -= 1
        y -= 1
        r[x] += z - a[x][y]
        c[y] += z - a[x][y]
        a[x][y] = z.toLong()
        print("${f(r) + f(c)} ")
    }
}