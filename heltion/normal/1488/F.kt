import java.util.*

fun main(){
    val n = readLine()!!.toInt()
    val c = listOf(Long.MAX_VALUE) + readLine()!!.split(' ').map { it.toLong() }
    val queries = Array(n + 1){ mutableListOf<Pair<Int, Int>>()}
    val q = readLine()!!.toInt()
    repeat(q){ i ->
        val (l, r) = readLine()!!.split(' ').map {it.toInt()}
        queries[r].add(Pair(l, i))
    }
    val bit1 = LongArray(n + 1)
    val bit2 = LongArray(n + 1)
    fun update(x : Int, v : Long){
        var i = x
        while(i <= n){
            bit1[i] += v
            bit2[i] += v * x
            i += i and -i
        }
    }
    fun get(x : Int) : Long{
        var i = x
        var v = 0L
        while(i > 0){
            v += (x + 1) * bit1[i]
            v -= bit2[i]
            i -= i and -i
        }
        return v
    }
    val ans = LongArray(q)
    val stack = Stack<Int>()
    stack.push(0)
    for(i in 1..n){
        while(!stack.empty() && c[stack.peek()] <= c[i]){
            val d = c[i] - c[stack.peek()]
            val r = stack.peek()
            stack.pop()
            val l = stack.peek() + 1
            update(l, d)
            update(r + 1, -d)
        }
        stack.push(i)
        update(i, c[i])
        update(i + 1, -c[i])
        for(p in queries[i])
            ans[p.second] = get(i) - get(p.first - 1)
    }
    for(x in ans) print("$x ")
}