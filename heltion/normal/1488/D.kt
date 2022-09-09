fun main(){
    repeat(readLine()!!.toInt()){
        val (n, s) = readLine()!!.split(' ').map { it.toLong() }
        var l = 1L
        var r = s
        while(l < r){
            val m = l + (r - l + 1) / 2
            var sum = n
            var x = m
            var i = 0
            while(x > 1 && i < n){
                sum += x - 1
                x = (x + 1) / 2
                i += 1
            }
            if(sum > s) r = m - 1
            else l = m
        }
        println(l)
    }
}