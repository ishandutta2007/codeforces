fun main(){
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map(String::toInt).sorted()
        var ok = a.count{it % 2 == 0} % 2 == 0
        for(i in 1 until n)
            if(a[i] == a[i - 1] + 1)
                ok = true
        println(if(ok)"YES" else "NO")
    }
}