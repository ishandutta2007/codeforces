
fun solve() {
    val n = readInt()
    val a = readInts()
    val q = readInt()
    class Node(var sum: Long) {
        var set = -1

        fun apply(value: Int, l: Int, r: Int) {
            set = value
            sum = 1L * value * (r - l)
        }
    }
    fun join(a: Node, b: Node): Node {
        return Node(a.sum + b.sum)
    }
    var pw = 1
    while (pw < n) pw *= 2
    val tree = Array(2 * pw) { Node(0L) }
    fun push(v: Int, l: Int, r: Int) {
        val m = (l + r) / 2
        if (tree[v].set >= 0) {
            tree[2 * v].apply(tree[v].set, l, m)
            tree[2 * v + 1].apply(tree[v].set, m, r)
        }
        tree[v].set = -1
    }
    fun rangeSet(ql: Int, qr: Int, toSet: Int) {
        fun rec(v: Int, l: Int, r: Int) {
            if (l >= qr || ql >= r) return
            if (ql <= l && r <= qr) {
                tree[v].apply(toSet, l, r)
                return
            }
            push(v, l, r)
            val m = (l + r) / 2
            rec(2 * v, l, m)
            rec(2 * v + 1, m, r)
            tree[v] = join(tree[2 * v], tree[2 * v + 1])
        }
        rec(1, 0, pw)
    }
    fun getSum(ql: Int, qr: Int): Long {
        fun rec(v: Int, l: Int, r: Int): Long {
            if (l >= qr || ql >= r) return 0L
            if (ql <= l && r <= qr) return tree[v].sum
            push(v, l, r)
            val m = (l + r) / 2
            return rec(2 * v, l, m) + rec(2 * v + 1, m, r)
        }
        return rec(1, 0, pw)
    }

    data class Query(val from: Int, val index: Int)
    val qs = Array(n) { ArrayList<Query>() }
    repeat(q) {
        val (l, r) = readInts()
        qs[r - 1].add(Query(l - 1, it))
    }
    val answers = LongArray(q)
    val st = ArrayDeque<Int>()
    repeat(n) { r ->
        val cur = a[r]
        while (!st.isEmpty() && a[st.last()] < cur) {
            st.removeLast()
        }
        val upto = if (st.isEmpty()) -1 else st.last()
        rangeSet(upto + 1, r + 1, cur)
        for (query in qs[r]) {
            answers[query.index] = getSum(query.from, r + 1)
        }
        st.addLast(r)
    }
    println(answers.joinToString(" "))
}

fun main() {
//    repeat(readInt()) {
        solve()
//    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles