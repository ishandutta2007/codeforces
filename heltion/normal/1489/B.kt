fun main() {
    repeat(readLine()!!.toInt()){
        var (n, a, b) = readLine()!!.split(' ').map{it.toLong()}
        b = minOf(2 * a, b)
        println(n / 2 * b + n % 2 * a)
    }
}