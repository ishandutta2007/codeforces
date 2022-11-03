import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val cons = Array(n) { mutableListOf<Int>() }
    repeat(m) {
        val a = br.readInt() - 1
        val b = br.readInt() - 1
        cons[a].add(b)
        cons[b].add(a)
    }
    val curTopicNums = IntArray(n)
    fun comp(a: Pair<Int, Int>, b: Pair<Int, Int>): Int{
        return a.second.compareTo(b.second)
    }
    val goalTopicNums = Array(n){ id ->
        Pair(id, br.readInt())
    }.sortedArrayWith(Comparator(::comp))

    var good = true
    val sb = StringBuilder()

    for(goalTopic in goalTopicNums){
        val node = goalTopic.first
        val neededTopic = goalTopic.second
        curTopicNums[node] = neededTopic
        sb.append(node + 1).append(' ')
        val used = BooleanArray(goalTopic.second)
        var numBelow = 0
        for(con in cons[node]){
            val adjTopic = curTopicNums[con]
            if(adjTopic in 1 until neededTopic){
                if(!used[adjTopic - 1]){
                    used[adjTopic - 1] = true
                    numBelow++
                }
            } else if(adjTopic == neededTopic){
                good = false
                break
            }
        }
        good = good && numBelow == neededTopic - 1
        if(!good){
            break
        }
    }
    if(!good){
        print(-1)
    } else {
        print(sb)
    }
}


private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()
@Suppress("DuplicatedCode")
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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}