fun main() {
    var (x, y, z) = readLine()!!.split(' ').map(String::toInt)
    var (a, b, c) = readLine()!!.split(' ').map(String::toInt)

    if (a >= x && a + b >= x + y && a + b + c >= x + y + z) {
        println("YES")
    } else {
        println("NO")
    }
}