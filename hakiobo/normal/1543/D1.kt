import kotlin.system.exitProcess

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
//        if (k == 2) {
//            println(0)
//            if (readLine() == "0") {
//                for (initPass in 1 until n) {
//                    println(initPass xor (initPass - 1))
//                    if (readLine() == "1") break
//                }
//            }
//        } else {
        var solved = false
        println(0)
        if (readLine() == "0") {
            for (initialPassWord in 1 until n) {
                var base = initialPassWord
                var other = initialPassWord - 1
                var mult = 1
                var guess = 0
                if (initialPassWord and 1 == 0) {
                    while (base > 0) {
                        var part = (base - other) % k
                        if (part < 0) part += k
                        guess += mult * part
                        base /= k
                        other /= k
                        mult *= k
                    }
                } else {
                    while (base > 0) {
                        var part = (other - base) % k
                        if (part < 0) part += k
                        guess += mult * part
                        base /= k
                        other /= k
                        mult *= k
                    }
                }

                println(guess)
                if ("1" == readLine()) {
                    solved = true
                    break
                }
            }
        } else {
            solved = true
        }
        if (!solved) exitProcess(0)
    }
//    }
}