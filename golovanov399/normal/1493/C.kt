import kotlin.random.*

fun solve() {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val s = readLine()!!
//    val s = CharArray(n) { 'a' + Random.nextInt(0..25) }.joinToString("")
    if (n % k != 0) {
        println("-1")
        return
    }
    var can = n / k
    var rem = IntArray(26) { 0 }
    var ans = CharArray(n)
    var are_we_greater = false

    var len_same = IntArray(n) { 0 }
    for (i in n - 1 downTo 0) {
        len_same[i] = 1
        if (i < n - 1 && s[i + 1] == s[i]) {
            len_same[i] += len_same[i + 1]
        }
    }

    fun can_continue(from: Int): Boolean {
        var i = from
        for (j in 25 downTo 0) {
            if (rem[j] == 0) {
                continue
            }
            if (s[i] != 'a' + j) {
                return s[i] < 'a' + j
            }
            if (len_same[i] >= rem[j]) {
                i += rem[j]
            } else {
                return s[i + len_same[i]] < 'a' + j
            }
        }
        return true
    }

    fun check(i: Int): Boolean {
        if (!are_we_greater && ans[i] < s[i]) {
            return false
        }
        if (can == 0 && rem[ans[i].hashCode() - 'a'.hashCode()] == 0) {
            return false
        }
        if (are_we_greater || ans[i] > s[i]) {
            return true
        }

        val need = if (rem[ans[i].hashCode() - 'a'.hashCode()] == 0) 1 else 0
        can -= need
        rem[ans[i].hashCode() - 'a'.hashCode()] += need * k - 1
        rem[25] += k * can
        val res = can_continue(i + 1)
        rem[25] -= k * can
        rem[ans[i].hashCode() - 'a'.hashCode()] -= need * k - 1
        can += need

        return res
    }

    for (i in 0 until n) {
        ans[i] = 'a'
        for (j in 0 until 26) {
            if (!check(i)) {
                ans[i] = ans[i] + 1
            } else {
                break
            }
        }
        if (ans[i] > 'z') {
            println("-1")
            return
        }
        if (rem[ans[i].hashCode() - 'a'.hashCode()] == 0) {
            can -= 1
            rem[ans[i].hashCode() - 'a'.hashCode()] += k
        }
        rem[ans[i].hashCode() - 'a'.hashCode()] -= 1
        if (ans[i] != s[i]) {
            are_we_greater = true
        }
    }
    println(ans.joinToString(""))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}