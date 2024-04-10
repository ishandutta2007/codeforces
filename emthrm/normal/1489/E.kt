import kotlin.math.min

const val M = 200000
fun main(args: Array<String>) {
    var pos = Array(M, {0})
    var l = 0
    var r = -1
    var q = readLine()!!.toInt()
    repeat(q) {
        var input = readLine()!!.split(" ")
        var id = input[1].toInt() - 1
        if (input[0] == "L") {
            --l
            pos[id] = l
        } else if (input[0] == "R") {
            ++r
            pos[id] = r
        } else if (input[0] == "?") {
            println(min(pos[id] - l, r - pos[id]))
        }
    }
}