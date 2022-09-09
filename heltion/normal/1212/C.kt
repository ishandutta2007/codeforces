fun main() {
    var (n, k) = readLine()!!.split(' ').map{it.toInt()}
    var a = readLine()!!.split(' ').map{it.toInt()}.sorted()
    if(k == 0) print(if(a[0] == 1) -1 else 1)
    else if(k == n) print(a[k - 1])
    else if(a[k] > a[k - 1]) print(a[k - 1])
    else print(-1)
}