const val n = 200000
val p = mutableListOf<Long>()
val cp = BooleanArray(n)
val phi = LongArray(n){1}
fun gcd(a : Long, b : Long) : Long{
    return if(b == 0L) a else gcd(b, a % b)
}
fun phi(t : Int, x : Long) : Long{
    if(x < n) return phi[x.toInt()]
    for(i in t until n) if(x % i == 0L){
        var p = i.toLong()
        while(x / p % i == 0L){
            p *= i
        }
        return phi(i, x / p) * p / i * (i - 1)
    }
    return x - 1
}
fun main(){
    for(i in 2 until n){
        if(!cp[i]){
            p.add(i.toLong())
            phi[i] = i.toLong() - 1
        }
        for(j in p){
            val k = i * j
            if(k >= n) break
            cp[k.toInt()] = true
            if(i % j == 0L){
                phi[k.toInt()] = phi[i] * j
                break
            }
            phi[k.toInt()] = phi[i] * (j - 1)
        }
    }
    repeat(readLine()!!.toInt()){
        val (a, m) = readLine()!!.split(' ').map {it.toLong()}
        println(phi(2, m / gcd(a, m)))
    }
}