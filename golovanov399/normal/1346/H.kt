import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

fun solve() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var start = mutableListOf<Pair<Int, Int>>()
    repeat (n) {
        val (x, y) = readLine()!!.split(' ').map(String::toInt)
        start.add(Pair(x + y, y - x))
    }

    var finish = mutableMapOf<Int, MutableList<Int>>()
    repeat (m) {
        val (x, y) = readLine()!!.split(' ').map(String::toInt)
        if (finish.containsKey(x + y)) {
            finish[x + y]!!.add(y - x)
        } else {
            finish[x + y] = mutableListOf(y - x)
        }
    }

    for ((k, v) in finish) {
        finish[k] = v.sorted().distinct().toMutableList()
    }

    fun getMaxLen(sum: Int, bound: Int): Int {
        if (!finish.containsKey(sum)) {
            return -1
        }
        val res = finish[sum]!!.binarySearch(bound)
        if (res >= 0) {
            return bound
        } else if (res == -1) {
            return -1
        } else {
            return finish[sum]!![-res - 2]
        }
    }

    var ans = mutableListOf<Int>()
    for ((sum, len) in start) {
        if (finish.containsKey(sum) && finish[sum]!!.binarySearch(len) >= 0) {
            ans.add(0)
            continue
        }
        if (len == 1) {
            ans.add(-1)
            continue
        }
        val bounds = mutableListOf(getMaxLen(sum - 2, len - 2), getMaxLen(sum, len - 2), getMaxLen(sum + 2, len - 2))
        var ans_left = -1
        var ans_right = -1
        if (bounds[0] != -1 || bounds[1] != -1) {
            ans_left = (len - max(bounds[0], bounds[1])) / 2
        }
        if (bounds[1] != -1 || bounds[2] != -1) {
            ans_right = (len - max(bounds[1], bounds[2])) / 2
        }
        ans.add(if (ans_left == -1 || ans_right == -1) -1 else max(ans_left, ans_right))
    }
    println(ans.joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()

    repeat (t) {
        solve()
    }
}