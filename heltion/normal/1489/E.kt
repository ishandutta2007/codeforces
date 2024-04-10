import java.util.*

fun main() {
    val positions = TreeMap<Int, Int>()
    var l = 0
    var r = 1
    repeat(readLine()!!.toInt()){
        val (t, ids) = readLine()!!.split(' ')
        val id = ids.toInt()
        if(t == "L") positions[id] = l --
        else if(t == "R") positions[id] = r ++
        else println(minOf(positions[id]!! - l - 1, r - positions[id]!! - 1))
    }
}