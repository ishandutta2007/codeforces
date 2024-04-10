fun main(){
    var (n, m) = readLine()!!.split(' ').map({it.toInt()})
    var a = Array(n + 1){IntArray(m)}
    for(i in 1..n)
        a[i] = readLine()!!.split(' ').map({it.toInt()}).toIntArray()
    var L = 0
    var R = 1000000000
    while(L < R){
        var M = (L + R + 1) / 2
        var v = BooleanArray(1 shl m)
        for(i in 1..n){
            var x = 0
            for(j in 0 until m)
                if(a[i][j] >= M)
                    x = x or (1 shl j)
            v[x] = true
        }
        var ok = false
        for(i in 1 until (1 shl m)) if(v[i])
            for(j in 1 until (1 shl m)) if(v[j])
                if((i or j) == (1 shl m) - 1)
                    ok = true
        if(ok) L = M
        else R = M - 1
    }
    var v = IntArray(1 shl m)
    for(i in 1..n){
        var x = 0
        for(j in 0 until m)
            if(a[i][j] >= L)
                x = x or (1 shl j)
        v[x] = i
    }
    for(i in 1 until (1 shl m)) if(v[i] != 0)
        for(j in 1 until (1 shl m)) if(v[j] != 0)
            if((i or j) == (1 shl m) - 1){
                println("${v[i]} ${v[j]}")
                return
            }
}