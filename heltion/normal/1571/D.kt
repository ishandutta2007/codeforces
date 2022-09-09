import kotlin.math.max

fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val (n, m) = readInts()
    val fls = Array(m){readInts().map { it - 1 }}
    val sf = IntArray(n)
    val sl = IntArray(n)
    val sfl = Array(n){IntArray(n)}
    for (fl in fls) {
        val (f, l) = fl
        sf[f] += 1
        sl[l] += 1
        sfl[f][l] += 1
    }
    var ans = 0
    for (f in 0 until n)
        for (l in 0 until n)
            if (f != l){
                var pans = 1
                if (fls[0][0] == f && fls[0][1] == l);
                else if (fls[0][0] == f) pans = sfl[f][l] + 1
                else if (fls[0][1] == l) pans = sfl[f][l] + 1
                else pans = sf[f] + sl[l] - sfl[f][l] + 1
                ans = maxOf(ans, pans)
            }
    println(ans)
}