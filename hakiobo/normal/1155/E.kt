import kotlin.system.exitProcess

fun main() {
    val mod = 1_000_003
    fun query(a: Int): Int {
        println("? $a")
        val result = readLine()!!.toInt()
        if (result == -1) exitProcess(0)
        return result
    }


    val difs = Array(11) { idx ->
        if (idx == 0) {
            IntArray(11) { toQ -> query(toQ) }
        } else {
            IntArray(11 - idx)
        }
    }
    val results = Array(mod) {
        IntArray(11)
    }
    results[0][0] = difs[0][0]
    for (level in 1 until 11) {
        for (x in 0 until difs[level].size) {
            difs[level][x] = (mod + difs[level - 1][x + 1] - difs[level - 1][x]) % mod
        }
        results[0][level] = difs[level][0]
    }
    var ans = if (results[0][0] == 0) 0 else -1

    for (x in 1 until mod) {
        results[x][10] = results[x - 1][10]
        for (level in 9 downTo 0) {
            results[x][level] = (results[x - 1][level] + results[x - 1][level + 1]) % mod
        }
        if (results[x][0] == 0) ans = x
    }
    println("! $ans")
}