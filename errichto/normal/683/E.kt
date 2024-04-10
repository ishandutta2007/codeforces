fun main(args: Array<String>) {
    val ma = 5000
    val arr = Array(ma, { i -> 0 })
    
    val (n) = readLine()!!.split('#').map(String::toInt)
    
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
            arr[poi] = liczba
            poi = poi + 1
        }
    
    for(rep in 0..(n-1))
        loop@ for(i in 1..n) if(arr[i] == 0) {
            for(j in 1..(i-1)) if(arr[j] >= 0) arr[j] = arr[j] - 1
            arr[i] = -1
            print(i)
            print(" ")
            break@loop
        }
}