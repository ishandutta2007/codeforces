import java.util.*
import kotlin.math.max
data class Movie(val a : Int, val b : Int, val id : Int)
fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    fun readLongs() = readLine()!!.split(' ').map(String::toLong)
    repeat(readInt()){
        val (n, m) = readInts()
        var movies = Array(n){
            val (a, b) = readInts()
            Movie(a, b, it)
        }.sortedBy{it.a}
        val ans = IntArray(n)
        var d = 0
        var i = 0
        val set = TreeSet<Movie>(compareBy<Movie>({it.b}, {it.id}))
        while(i < n || set.isNotEmpty()){
            while(i < n && movies[i].a <= d){
                set.add(movies[i])
                i += 1
            }
            if(i < n && set.isEmpty()){
                d = movies[i].a
            }
            while(i < n && movies[i].a <= d){
                set.add(movies[i])
                i += 1
            }
            var tm = m
            while(tm > 0 && set.isNotEmpty()){
                ans[set.pollFirst().id] = d
                tm -= 1
            }
            d += 1
        }
        movies = movies.sortedBy{it.id}
        println(ans.withIndex().map{max(it.value - movies[it.index].b, 0)}.max())
        for(x in ans) print("$x ")
        println()
    }
}