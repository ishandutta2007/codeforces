fun main() {
    var (n, k) = readLine()!!.split(' ').map{it.toInt()}
    repeat(k) {
        n = if (n % 10 == 0) n / 10 else n - 1
    }
    print(n)
}