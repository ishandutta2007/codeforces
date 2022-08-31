import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val x = readLine()!!.split(' ').map(String::toInt)
    val d = readLine()!!.split(' ').map { if (it == "L") -1 else 1 }
    data class Robot(val pos: Int, val dir: Int, val id: Int)
    val robots = (0 until n).map { i -> Robot(x[i], d[i], i) }

    val answer = IntArray(n) { -1 }
    (0..1).forEach { rem ->
        val cur = robots.filter { it.pos % 2 == rem }.sortedBy { it.pos }
        val (left, right) = List(2) { mutableListOf<Robot>() }
        fun fillAnswer(a: Robot, b: Robot, res: Int) {
            answer[a.id] = res
            answer[b.id] = res
        }
        cur.forEach { r ->
            if (r.dir == -1) {
                if (right.isNotEmpty()) {
                    val res = (r.pos - right.last().pos) / 2
                    fillAnswer(right.removeLast(), r, res)
                } else {
                    left.add(r)
                }
            } else {
                right.add(r)
            }
        }
        right.reverse()
        fun toBorder(r: Robot): Int = if (r.dir == -1) r.pos else m - r.pos
        fun handle(l: List<Robot>) {
            val res = l.map { r -> toBorder(r) }.sum() / 2
            l.forEach { r ->
                answer[r.id] = res
            }
        }
        val lonely = mutableListOf<Robot>()
        listOf(left, right).forEach { list ->
            list.chunked(2).forEach {
                if (it.size == 2) {
                    handle(it)
                } else {
                    lonely.add(it.single())
                }
            }
        }
        if (lonely.size == 2) {
            handle(lonely.map { r -> if (r.dir == 1) r else Robot(r.pos + m, r.dir, r.id) })
        }
    }
    println(answer.joinToString(" "))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}