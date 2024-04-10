import kotlin.math.*

const val mod = 998_244_353

fun reduceInt(x: Int): Int {
    return x - (if (x >= mod) mod else 0)
}

fun reduce(x: Long): Int {
    return (x % mod).toInt()
}

fun intInv(x: Int): Int = if (x == 1) {
    1
} else {
    mod - reduce(intInv(mod % x) * (mod / x).toLong())
}

class Mint(private val x: Int) {
    operator fun plus(ot: Mint) = Mint(reduceInt(x + ot.x))
    operator fun plus(ot: Int) = Mint(reduceInt(x + ot))
    operator fun minus(ot: Mint) = Mint(reduceInt(x + mod - ot.x))
    operator fun times(ot: Mint) = Mint(reduce(1L * x * ot.x))
    override fun toString() = x.toString()
    fun equals(ot: Mint) = x == ot.x
    fun inv(): Mint {
        return Mint(intInv(x))
    }
}

fun areGood(s: String, t: String): Boolean = s.endsWith(t) || t.endsWith(s)

fun findLinearRecurrence(a: List<Mint>): List<Mint> {
    var p = mutableListOf<Mint>()
    fun get(idx: Int): Mint = p.indices.map { i ->
        p[i] * a[idx - 1 - i]
    }.reduceOrNull(Mint::plus) ?: Mint(0)
    var lastIncorrect = mutableListOf<Mint>()
    var lastIdx = -1
    for (i in a.indices) {
        val cur = get(i)
        if (cur.equals(a[i])) {
            continue
        }
        var newP = p.toMutableList()
        var needToUpdate = true
        if (newP.isEmpty()) {
            newP = MutableList(i + 1) { Mint(0) }
        } else {
            val sz = (i - lastIdx - 1) + lastIncorrect.size
            if (sz > newP.size) {
                while (newP.size < sz) {
                    newP.add(Mint(0))
                }
            } else {
                needToUpdate = false
            }
            for (j in lastIncorrect.indices) {
                newP[i - lastIdx - 1 + j] += lastIncorrect[j] * (a[i] - cur)
            }
        }
        if (needToUpdate) {
            lastIncorrect = p.toMutableList()
            lastIncorrect.add(0, Mint(mod - 1))
            val toDiv = (cur - a[i]).inv()
            lastIncorrect.replaceAll { it * toDiv }
            lastIdx = i
        }
        p = newP.toMutableList()
    }
    return p.toList()
}

fun getNthTermOfRecurrence(rec: List<Mint>, initial: List<Mint>, n: Int): Mint {
    if (n < initial.size) {
        return initial[n]
    }
    val sz = rec.size
    fun mult(a: List<Mint>, b: List<Mint>): List<Mint> {
        val res = MutableList(sz * 2) { Mint(0) }
        for (i in 0 until sz) {
            for (j in 0 until sz) {
                res[i + j] += a[i] * b[j]
            }
        }
        for (i in (2 * sz - 1) downTo sz) {
            if (res[i].equals(Mint(0))) {
                continue
            }
            for (j in 0 until sz) {
                res[i - 1 - j] += res[i] * rec[j]
            }
        }
        return res.take(sz)
    }

    if (sz == 1) {
        var answer = initial[0]
        var cur = rec[0]
        var d = n
        while (d > 0) {
            if (d % 2 > 0) {
                answer *= cur
            }
            d /= 2
            cur *= cur
        }
        return answer
    }

    var res = List(sz) { Mint(if (it == 0) 1 else 0) }
    var a = List(sz) { Mint(if (it == 1) 1 else 0) }
    var d = n
    while (d > 0) {
        if (d % 2 > 0) {
            res = mult(res, a)
        }
        d /= 2
        a = mult(a, a)
    }
    return (0 until sz).map { res[it] * initial[it] }.reduce(Mint::plus)
}

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    val dict = (0 until n).map { readLine()!! }
    val positions = (0 until n).map { i -> dict[i].indices.map { j -> i to (j + 1) } }.flatten()
    val pairPositions = positions.indices.map { i ->
        (0..i).filter { j ->
            areGood(
                    dict[positions[i].first].take(positions[i].second),
                    dict[positions[j].first].take(positions[j].second),
            )
        }.map { j -> j to i }
    }.flatten()

    fun findPair(i_1: Int, l_1: Int, i_2: Int, l_2: Int): Int? {
        val pos1 = positions.indexOf(i_1 to l_1)
        val pos2 = positions.indexOf(i_2 to l_2)
        val p = min(pos1, pos2) to max(pos1, pos2)
        return if (p in pairPositions) pairPositions.indexOf(p) else null
    }

    val sz = pairPositions.size
    val transitions = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until sz) {
        val (pos_1, pos_2) = pairPositions[i]
        val (i_1, l_1) = positions[pos_1]
        val (i_2, l_2) = positions[pos_2]
        val newIl = listOf(pos_1, pos_2).filter { p ->
            val (j, l) = positions[p]
            l < dict[j].length
        }.map { p -> positions[p].first to positions[p].second + 1 }
        if (l_1 < dict[i_1].length && l_2 < dict[i_2].length) {
            if (dict[i_1][l_1] == dict[i_2][l_2]) {
                val j = findPair(i_1, l_1 + 1, i_2, l_2 + 1)!!
                transitions.add(i to j)
            }
        } else if (newIl.size == 1) {
            val (idx, l) = newIl[0]
            val need = dict[idx][l - 1]
            for (j in 0 until n) {
                if (dict[j][0] == need) {
                    val nj = findPair(idx, l, j, 1)!!
                    transitions.add(i to nj)
                }
            }
        } else {
            assert(newIl.isEmpty())
            for (j_1 in 0 until n) {
                for (j_2 in 0 until n) {
                    if (dict[j_1][0] == dict[j_2][0]) {
                        val nj = findPair(j_1, 1, j_2, 1)!!
                        transitions.add(i to nj)
                    }
                }
            }
        }
    }

    val initial = findPair(0, dict[0].length, 0, dict[0].length)!!
    var vals = List(sz) { Mint(if (it == initial) 1 else 0) }
    val seq = mutableListOf<Mint>()
    val wanted = pairPositions.withIndex().filter { (_, value) ->
        val (pos_1, pos_2) = value
        val (i_1, l_1) = positions[pos_1]
        val (i_2, l_2) = positions[pos_2]
        dict[i_1].length == l_1 && dict[i_2].length == l_2
    }.map { it.index }
    repeat(2 * sz) {
        seq.add(wanted.map { vals[it] }.reduce(Mint::plus))
        val tmp = MutableList(sz) { Mint(0) }
        for ((i, j) in transitions) {
            tmp[j] += vals[i]
        }
        vals = tmp.toList()
    }

    val rec = findLinearRecurrence(seq)
    println(getNthTermOfRecurrence(rec, seq, m))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}