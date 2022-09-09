import java.util.*
class cmp : Comparator<Pair<Int, Int>>{
    override fun compare(o1: Pair<Int, Int>?, o2: Pair<Int, Int>?): Int {
        return if(o1!!.first == o2!!.first) o1!!.second - o2!!.second else o1!!.first - o2!!.first
    }
}
fun main(){
    val n = readLine()!!.toInt()
    val d = Array(n + 1){ mutableListOf<Int>()}
    for(i in 1..n)
        for(j in 2 * i..n step i)
            d[j].add(i)
    val pq = TreeSet<Pair<Int, Int>>(cmp())
    val v = IntArray(n + 1)
    val q = Array(2 * n + 1){ mutableListOf<Int>()}
    for(i in 1..n){
        v[i] = d[i].size
        q[n + v[i]].add(i)
    }
    val painted = BooleanArray(n + 1)
    var ans = 0
    for(i in n downTo -n) {
        for(u in q[n + i]) {
            if(painted[u] || v[u] != i) continue
            painted[u] = true
            ans += i
            print("$ans ")
            for (x in d[u]) if (!painted[x]) {
                v[x] -= 1
                q[n + v[x]].add((x))
            }
            for (x in u + u..n step u) if (!painted[x]) {
                v[x] -= 1
                q[n + v[x]].add((x))
            }
        }
    }
}