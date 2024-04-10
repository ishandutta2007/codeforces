import java.util.*

fun main() {
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    val (n, a, b, k) = readInts()
    val r = readInts()
    val map = TreeMap<Int, Int>()
    for (x in r) {
        if (!map.containsKey(x)) map[x] = 0
        map[x] = map[x]!! + 1
    }
    var ans = 0
    if(a < b){
        for(x in map.keys.reversed()){
            if(x % k == 0 && map.containsKey(x / k)){
                val d = minOf(map[x]!! / b, map[x / k]!! / a)
                ans += d
                map[x / k] = map[x / k]!! - d * a
            }
        }
    }
    else{
        for(x in map.keys){
            if(map.containsKey(x * k)){
                val d = minOf(map[x]!! / a, map[x * k]!! / b)
                ans += d
                map[x * k] = map[x * k]!! - d * b
            }
        }
    }
    println(ans)
}