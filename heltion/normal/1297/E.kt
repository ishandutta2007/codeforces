import java.util.*
import kotlin.math.abs
import kotlin.math.min

fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(readInt()){
        val (n, k) = readInts()
        val adj = Array(n){ mutableListOf<Int>()}
        val deg = IntArray(n)
        repeat(n - 1){
            val (u, v) = readInts().map{it - 1}
            adj[u].add(v)
            adj[v].add(u)
            deg[u] += 1
            deg[v] += 1
        }
        val q = LinkedList<Int>()
        for(u in 0 until n)
            if(deg[u] == 1) q.addLast(u)
        if(k == 1){
            println("Yes")
            println(1)
            println(1)
        }
        else if(q.size < k) println("No")
        else{
            println("Yes")
            val set = (0 until n).toMutableSet()
            if(q.size > k) while(q.isNotEmpty()){
                val u = q.pollFirst()
                set.remove(u)
                for(v in adj[u]){
                    deg[v] -= 1
                    if(deg[v] == 1) q.add(v)
                }
                if(q.size == k) break
            }
            println(set.size)
            for(x in set) print("${x + 1} ")
            println()
        }
    }
}