fun solve() {
    readLine()!!
    val s = readLine()!!
    val p = MutableList(26) { -1 }
    val b = MutableList(26) { -1 }
    var cnt = 0
    s.forEach { c ->
        if (p[c - 'a'] == -1) {
            if (cnt == 25) {
                p[c - 'a'] = b[c - 'a']
            } else {
                p[c - 'a'] = (0..25).first { it != c - 'a' && it != b[c - 'a'] && b[it] == -1 }
                b[p[c - 'a']] = if (b[c - 'a'] == -1) c - 'a' else b[c - 'a']
                (0..25).forEach {
                    if (b[it] > -1 && b[b[it]] > -1) {
                        b[it] = b[b[it]]
                    }
                }
            }
            cnt += 1
        }
    }
    println(s.map { 'a' + p[it - 'a'] }.joinToString(""))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}