import java.util.*
import kotlin.math.*

data class Node(var edges: TreeMap<Int, Int>, var link: Int, var len: Int) {}

class SufAutomaton {
    private var a = mutableListOf(Node(TreeMap(), -1, 0))
    private var last = 0

    fun newState(): Int {
        val res = a.size
        a.add(Node(TreeMap(), -1, 0))
        return res
    }

    fun clone(x: Int): Int {
        val res = a.size
        a.add(a[x].copy())
        return res
    }

    fun add(c: Int) {
        val cur = newState()
        a[cur].len = a[last].len + 1
        var p = last
        while (p >= 0 && !a[p].edges.containsKey(c)) {
            a[p].edges[c] = cur
            p = a[p].link
        }

        if (p != -1) {
            val q = a[p].edges[c]!!
            if (a[p].len + 1 == a[q].len) {
                a[cur].link = q
            } else {
                val nw = newState()
                a[nw].edges = a[q].edges.clone() as TreeMap<Int, Int>
                a[nw].len = a[p].len + 1
                a[nw].link = a[q].link
                while (p >= 0 && a[p].edges[c]!! == q) {
                    a[p].edges[c] = nw
                    p = a[p].link
                }
                a[cur].link = nw
                a[q].link = nw
            }
        } else {
            a[cur].link = 0
        }
        last = cur
    }

    fun getMaxLen(s: IntArray, start: Int): Int {
        var len = 0
        var p = 0
        while (start + len < s.size && a[p].edges.containsKey(s[start + len])) {
            p = a[p].edges[s[start + len]]!!
            len += 1
        }
//        println("${s.joinToString(" ")}, $start: $len")
        return len
    }
}

fun solve() {
    val (n, m, q) = readLine()!!.split(' ').map(String::toInt)
    var sa = SufAutomaton()
    repeat(n) {
        val s = readLine()!!
        for (i in 0 until m) {
            sa.add(i * 26 + s[i].hashCode() - 'a'.hashCode())
        }
    }

    repeat(q) {
        val s = readLine()!!.mapIndexed { i, c -> i * 26 + c.hashCode() - 'a'.hashCode() }.toIntArray()
        var ans = -1
        var i = 0
        while (i < s.size) {
            val tmp = sa.getMaxLen(s, i)
            if (tmp == 0) {
                println(-1)
                break
            }
            i += tmp
            ans += 1
        }
        if (i == s.size) {
            println(ans)
        }
    }
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}