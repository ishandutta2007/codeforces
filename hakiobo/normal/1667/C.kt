fun main() {
    var n = readLine()!!.toInt()
    val bw = System.out.bufferedWriter()
    val ans = (2 * n + 1) / 3
    bw.appendLine("$ans")

    if (ans and 1 == 0) {
        bw.appendLine("$n $n")
        n--
    }
    val half = (ans + 1) shr 1
    for (x in 1..half) {
        bw.appendLine("$x ${half + 1 - x}")
    }
    for (x in 1 until half) {
        bw.appendLine("${n + 1 - x} ${n - half + 1 + x}")
    }
    bw.flush()
}