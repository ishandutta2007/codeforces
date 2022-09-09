fun main(){
    repeat(readLine()!!.toInt()){
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!
        var sum = 0
        var ans = 0
        for(c in s) {
            if (c == '(') sum += 1
            else sum -= 1
            if (sum == 0) ans += 1
        }
        println(ans + minOf(n / 2 - ans, k))
    }
}