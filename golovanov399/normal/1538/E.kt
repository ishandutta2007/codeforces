import kotlin.math.*
import kotlin.system.exitProcess

data class Haha(val count: Long, val left: String, val right: String)

fun merge(a: Haha, b: Haha): Haha {
    var total = a.count + b.count
    val between = a.right + b.left
    for (i in 0 until between.length - 3) {
        if (between.substring(i, i + 4) == "haha") {
            total += 1
        }
    }
    return Haha(
            total,
            a.left + b.left.take(min(3 - a.left.length, b.left.length)),
            a.right.takeLast(min(3 - b.right.length, a.right.length)) + b.right
    )
}

fun strToHaha(s: String): Haha {
    var res = 0
    for (i in 0 until s.length - 3) {
        if (s.substring(i, i + 4) == "haha") {
            res += 1
        }
    }
    return Haha(res.toLong(), s.take(min(3, s.length)), s.takeLast(min(3, s.length)))
}

fun solve() {
    val n = readLine()!!.toInt()
    val mp = mutableMapOf<String, Haha>()
    var last = ""
    repeat (n) {
        val instr = readLine()!!.split(' ')
        if (instr[1] == ":=") {
            mp[instr[0]] = strToHaha(instr[2])
        } else {
            mp[instr[0]] = merge(mp[instr[2]]!!, mp[instr[4]]!!)
        }
//        println("${instr[0]}: ${mp[instr[0]]!!}")
        last = instr[0]
    }
    println(mp[last]!!.count)
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}