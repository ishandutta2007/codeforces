fun main() {
    repeat (readLine()!!.toInt()) {
        val (a, b, k) = readLine()!!.split(' ').map(String::toLong)
        println(k / 2 * (a - b) + k % 2 * a)
    }
}