import kotlin.math.*

data class Gift(val friend: Int, val shop: Int, val cost: Int)

fun solve() {
    readLine()!!
    val (m, n) = readLine()!!.split(' ').map(String::toInt)
    val a = (0 until m).map { shop ->
        readLine()!!.split(' ').map(String::toInt).mapIndexed { friend, cost -> Gift(friend, shop, cost) }
    }.flatten().sortedBy { -it.cost }
    val byFriend = MutableList(n) { false }
    val byShop = MutableList(m) { 0 }
    var friendCount = 0
    var doubleShop = false
    for ((friend, shop, cost) in a) {
        if (!byFriend[friend]) {
            byFriend[friend] = true
            friendCount += 1
        }
        byShop[shop] += 1
        if (byShop[shop] >= 2) {
            doubleShop = true
        }
        if (doubleShop && friendCount == n) {
            println(cost)
            return
        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat (t) {
        solve()
    }
}