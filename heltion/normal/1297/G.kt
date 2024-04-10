var sum = 0L
var size = 0L
val r = LongArray(10)
fun add(){
    val x = r.clone()
    if(r.sum() > size) return
    x[1] = size - r.sum()
    x.sortDescending()
    var res = 1L
    for(a in x[0] + 1..size) res *= a
    for(i in 1 until 10)
        for(a in 1..x[i])
            res /= a
    sum += res
}
fun dfs(i : Int, n : Long){
    if(i == 10){
        if(n == 1L) add()
        return
    }
    if(n % i == 0L){
        r[i] += 1L
        dfs(i, n / i)
        r[i] -= 1L
    }
    dfs(i + 1, n)
}
fun count(n : Long, length : Long) : Long{
    sum = 0L
    size = length
    dfs(2, n)
    return sum
}
fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    val (n, k) = readLongs()
    var tn = n
    for(i in 2..7) while(tn % i == 0L) tn /= i
    if(tn > 1){
        println(-1)
        return
    }
    var acc = 0L
    var p = 0L
    while(acc < k){
        p += 1
        acc += count(n, p)
    }
    tn = n
    acc = (k - acc + sum)
    for(i in 0 until p){
        var pac = 0L
        var pp = 0L
        while(pac < acc){
            pp += 1
            if(tn % pp == 0L)
                pac += count(tn / pp, p - i - 1)
        }
        acc = (acc - pac + sum)
        print(pp)
        tn /= pp
    }
}