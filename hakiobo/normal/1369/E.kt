import java.io.BufferedReader
import java.util.*


fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val cts = IntArray(n) { br.readInt() }

    val revFavs = Array(n) { mutableListOf<Int>() }
    val visited = BooleanArray(m)
    val favs = Array(m) {
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        revFavs[a].add(it)
        revFavs[b].add(it)
        cts[a]--
        cts[b]--
        Pair(a, b)
    }
    val order = IntArray(m)
    var ptr = order.size
    val queue: Queue<Int> = ArrayDeque()
    for(i in cts.indices){
        if(cts[i] >= 0){
            queue += i
        }
    }
    while (queue.isNotEmpty()){
        val food = queue.poll()
        for(friend in revFavs[food]){
            if(!visited[friend]){
                visited[friend] = true
                order[--ptr] = friend + 1
                if(++cts[favs[friend].first] == 0){
                    queue += favs[friend].first
                }
                if(++cts[favs[friend].second] == 0){
                    queue += favs[friend].second
                }
            }
        }
    }
    if(ptr == 0){
        println("ALIVE")
        print(order.joinToString(" "))
    } else {
        print("DEAD")
    }
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}