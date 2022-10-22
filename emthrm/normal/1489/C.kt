fun main(args: Array<String>) {
    readLine()
    var name = readLine()!!
    var ans = 0
    var x = 0
    name.forEach {
        if (it == 'x') {
            if (x == 2) {
              ++ans
            } else {
              ++x
            }
        } else {
            x = 0
        }
    }
    println(ans)
}