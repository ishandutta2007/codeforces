fun main() {
    val (n, m, k) = readLine()!!.split(' ').map{it.toInt()}
    val a = readLine()!!.split(' ').map{it.toInt()}
    var l = 1
    var r = n
    while(l < r){
        val mid = (l + r + 1) / 2
        var rk = k
        var rm = 1
        for(i in n - mid until n){
            if(rk >= a[i]){
                rk -= a[i]
            }
            else{
                rm += 1
                rk = k - a[i]
            }
        }
        if(rm > m) r = mid - 1
        else l = mid
    }
    println(l)
}