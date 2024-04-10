fun main(args: Array<String>) {
    val ma = 5000
    val arr = Array(ma, { i -> 0 })
    for(rep in 0..1) {
        var (s) = readLine()!!.split('#')
        for(j in 0..s.length-1) if(s[j] == ' ') {
            var tmp = ""
            loop@ for(k in (j+1)..(j+10)) {
                if(k == s.length) break@loop
                if(s[k] == ' ') break@loop
                tmp = tmp + s[k]
            }
            var liczba = tmp.toInt()
            arr[liczba+ma/2] = arr[liczba+ma/2] + 1
        }
    }
    var cnt = 0
        for(i in 0..(ma-1))
        if(arr[i] == 1) {
        cnt = cnt + 1
        }
        print(cnt)
        print(" ")
    for(i in 0..(ma-1))
        if(arr[i] == 1) {
            print(i-ma/2)
            print(" ")
        }
}