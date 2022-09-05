fun main(args: Array<String>) {
    val (nn, k) = readLine()!!.split(' ').map(String::toLong)
    var n : Int = nn.toInt()
    val arr = Array(n + 5, { i -> 0 })
    val ans = Array(n + 5, { i -> 0 })
    
    var poi = 1
    
        var (s) = readLine()!!.split('#')
        s = " " + s
        for(j in 0..s.length-1) if(s[j] == ' ') {
            var tmp = ""
            loop@ for(k in (j+1)..(j+10)) {
                if(k == s.length) break@loop
                if(s[k] == ' ') break@loop
                tmp = tmp + s[k]
            }
            var liczba = tmp.toInt()
            arr[liczba] = poi
            poi = poi + 1
        }
    
    for(i in 1..n) if(ans[i] == 0) {
        var cnt = 1
        var x = arr[i]
        while(x != i) {
            ++cnt
            x = arr[x]
        }
        var here_tmp = k % cnt.toLong()
        var here = here_tmp.toInt()
        for(j in 1..here) x = arr[x]
        ans[i] = x
        var y = arr[i]
        var pre = ans[i]
        while(y != i) {
            pre = arr[pre]
            ans[y] = pre
            y = arr[y]
        }
    }
    for(i in 1..n) {
        print(ans[i])
        print(" ")
    }
}