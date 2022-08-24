import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

const val L = 5
const val inf = 1e9.toInt()

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until n).map { readLine()!!.map { c -> c - 'A' } }
    val cnt = (0 until (1 shl L)).map { mask ->
        val b = a.map { l -> l.map { x -> (mask and (1 shl x)) == (1 shl x) } }
        var ans = 0L
        val h = MutableList(m) { 0 }
        for (i in 0 until n) {
            var s = 0
            var from = -1
            val st = mutableListOf<IndexedValue<Int>>()
            for (j in 0 until m) {
                if (b[i][j]) {
                    if (st.isEmpty()) {
                        from = j - 1
                    }
                    val nh = i - h[j] + 1
                    while (st.isNotEmpty() && st.last().value >= nh) {
                        val cur = st.removeLast().value
                        val old = if (st.isNotEmpty()) max(nh, st.last().value) else nh
                        s -= (cur - old) * (j - (if (st.isEmpty()) from else st.last().index) - 1)
                    }
                    st.add(IndexedValue(j, nh))
//                    if (mask == 20) {
//                        println(s)
//                    }
                    s += nh
                } else {
                    st.clear()
                    s = 0
                    h[j] = i + 1
                }
                ans += s
//                if (mask == 16 + 4) {
//                    println("$i, $j: $st, $s")
//                }
            }
        }
        ans
    }.toMutableList()
//    println(cnt)
    for (bit in 0 until L) {
        for (mask in 0 until (1 shl L)) {
            if ((mask and (1 shl bit)) == 0) {
                cnt[mask or (1 shl bit)] -= cnt[mask]
            }
        }
    }
//    println(cnt)
    println((1..L).map { k -> (0 until (1 shl L)).filter { it.countOneBits() == k }.sumOf { mask -> cnt[mask] } }.joinToString(" "))
//    println(cnt)
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}