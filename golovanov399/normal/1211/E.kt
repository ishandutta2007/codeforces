import kotlin.math.min
import kotlin.system.exitProcess

fun main() {
    var n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var l = 0
    var r = n
    while (r > l + 1) {
        val m = (l + r) / 2
        var st = mutableListOf<Int>()
        var used = IntArray(m) {0}
        var lcnt = 0
        var rcnt = 0
        var ok = true
        for (i in 0 until n) {
            if (a[i] <= m) {
                if (used[a[i] - 1] > 1) {
                    ok = false
                    break
                }
                if (used[a[i] - 1] == 1) {
                    used[a[i] - 1] += 1
                    val cnt = min(lcnt, rcnt)
                    if (cnt < st.size && st[cnt] == a[i]) {
                        if (lcnt < rcnt) {
                            lcnt += 1
                        } else {
                            rcnt += 1
                        }
                    } else {
                        ok = false
                        break
                    }
                } else {
                    st.add(a[i])
                    if (lcnt > rcnt) {
                        lcnt += 1
                    } else {
                        rcnt += 1
                    }
                    used[a[i] - 1] += 1
                }
            }
        }
        if (lcnt != m || rcnt != m) {
            ok = false
        }
        if (ok) {
            l = m
        } else {
            r = m
        }
    }

    var ans = mutableListOf<Char>()
    var used = BooleanArray(n) {false}
    var lcnt = 0
    var rcnt = 0
    for (i in 0 until n) {
        if (a[i] <= l) {
            if (used[a[i] - 1]) {
                if (lcnt < rcnt) {
                    lcnt += 1
                    ans.add('R')
                } else {
                    rcnt += 1
                    ans.add('G')
                }
            } else {
                if (lcnt > rcnt) {
                    lcnt += 1
                    ans.add('R')
                } else {
                    rcnt += 1
                    ans.add('G')
                }
                used[a[i] - 1] = true
            }
        } else {
            ans.add('B')
        }
    }

    println(ans.joinToString(""))
}