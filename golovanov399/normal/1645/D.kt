import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt).sorted()
    val fst = mutableListOf<Int>()
    val snd = mutableListOf<Int>()
    var i = 0
    while (i < n) {
        if (i < n - 2 && a[i] == a[i + 2]) {
            println("NO")
            return
        }
        if (i < n - 1 && a[i] == a[i + 1]) {
            fst.add(a[i])
            snd.add(a[i])
            i += 2
        } else {
            fst.add(a[i])
            i += 1
        }
    }
    println("YES")
    println(fst.size)
    println(fst.joinToString(" "))
    println(snd.size)
    println(snd.reversed().joinToString(" "))
}

fun main() {
    val t = 1 // readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}