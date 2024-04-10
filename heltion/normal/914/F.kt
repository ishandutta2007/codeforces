import java.util.*

fun main(){
    val s = StringBuilder(readLine()!!)
    val bitSets = Array(26){BitSet(s.length)}
    for((i, c) in s.withIndex()) bitSets[c - 'a'].flip(i)
    repeat(readLine()!!.toInt()){
        val input = readLine()!!.split(' ')
        if(input.size == 3){
            val i = input[1].toInt() - 1
            val c = input[2][0]
            bitSets[s[i] - 'a'].flip(i)
            s[i] = c
            bitSets[s[i] - 'a'].flip(i)
        }
        else{
            val l = input[1].toInt() - 1
            val r = input[2].toInt() - 1
            val y = input[3]
            if(r - l + 1 < y.length) println(0)
            else{
                var ans = BitSet(s.length)
                ans.set(l, r - y.length + 2)
                for ((i, c) in y.withIndex()) ans.and(bitSets[c - 'a'].get(i, s.length))
                println(ans.cardinality())
            }
        }
    }
}