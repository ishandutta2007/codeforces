var s = IntArray(0)
fun add(p : Int, x : Int){
    var i = p
    while(i < s.size){
        s[i] += x
        i += i and -i
    }
}
fun sum(p : Int) : Int{
    var sum = 0
    var i = p
    while(i > 0){
        sum += s[i]
        i -= i and -i
    }
    return sum
}
data class fuck(val R : Int, val id : Int)
fun main(){
    var (n, m) = readLine()!!.split(' ').map({it.toInt()})
    var L = IntArray(n + 1, {it})
    var R = IntArray(n + 1, {it})
    var a = readLine()!!.split(' ').map({it.toInt()}).toIntArray() 
    var v = IntArray(n + 1){-1}
    s = IntArray(n + 1)
    for(i in 0 until m){
        var x = a[i]
        L[x] = 1
        if(v[x] == -1){
            add(x, 1)
            R[x] = maxOf(R[x], x + sum(n) - sum(x))
        }
        v[x] = i
    }
    for(x in 1..n)
        if(v[x] == -1) 
            R[x] = maxOf(R[x], x + sum(n) - sum(x))
    s = IntArray(m + 2)
    v = IntArray(n + 1){m}
    for(i in m - 1 downTo 0){
        var x = a[i]
        add(i + 1, 1)
        if(v[x] != 0){
            add(v[x] + 1, -1)
            R[x] = maxOf(R[x], sum(v[x]) - sum(i))
        }
        v[x] = i    
    }
    for(i in 1..n) println("${L[i]} ${R[i]}")
}