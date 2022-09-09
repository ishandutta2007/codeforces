fun main() {
    repeat (readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        repeat (n) {
            print('a' + it % k)
        }
        println()
    }
}