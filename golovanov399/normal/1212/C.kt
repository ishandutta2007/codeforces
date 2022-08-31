fun main() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = readLine()!!.split(' ').map(String::toInt).toList().sorted()
    if (k == 0) {
        if (a[0] > 1) {
            println(1)
        } else {
            println(-1)
        }
    } else if (k < n && a[k - 1] == a[k]) {
        println(-1)
    } else {
        println(a[k - 1])
    }
}