import kotlin.system.exitProcess

fun main() {

    fun analyzeString(s: String): Long {
        var aSet = false
        var expectingH = true
        var count = 0L
        for (c in s) {
            when (c) {
                'h' -> {

                    if (!expectingH) {
                        aSet = false
                    }
                    expectingH = false

                }
                'a' -> {
                    if (expectingH) {
                        aSet = false
                    } else {
                        if (aSet) count++
                        aSet = true
                        expectingH = true
                    }
                }
                else -> {
                    expectingH = true
                    aSet = false
                }
            }
        }
        return count
    }
//    println(analyzeString("thaha"))
//    fun analyzeString(s: String): Long {
//        var ct = 0L
//        for (x in s.indices) {
//            if (s.drop(x).startsWith("haha")) ct++
//        }
//        return ct
//    }


    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val vars = FunnyTrie(n * 5 + 1)
        var ans = 0L
        repeat(n) {
            val statement = br.readLine().split(" ")
            val varToSet = statement.first()
            if (statement.size == 5) {
                val varA = vars.get(statement[2])
                val varB = vars.get(statement[4])
                val s = vars.suffix[varA] + vars.prefix[varB]
                val newCount = vars.numHaHa[varA] + vars.numHaHa[varB] + analyzeString(s)


                val (prefix, suffix) = if (vars.suffix[varA].length < 3 && vars.prefix[varB].length < 3) {
                    s.take(3) to s.takeLast(3)
                } else if (vars.suffix[varA].length < 3) {
                    s.take(3) to vars.suffix[varB]
                } else if (vars.prefix[varB].length < 3) {
                    vars.prefix[varA] to s.takeLast(3)
                } else {
                    vars.prefix[varA] to vars.suffix[varB]
                }
                vars.add(varToSet, newCount, prefix, suffix)
            } else {
                val s = statement.last()
                val count = analyzeString(s)
                vars.add(varToSet, count, s.take(3), s.takeLast(3))
            }
            ans = vars.numHaHa[vars.get(varToSet)]
        }
        sb.appendLine(ans)
    }
    print(sb)
}

private class FunnyTrie(n: Int) {

    var numNodes = 1
    val trie = Array(n) { IntArray(26) { -1 } }
    val numHaHa = LongArray(n) { -1 }
    val suffix = Array(n) { "" }
    val prefix = Array(n) { "" }

    fun get(s: String): Int {
        var curNode = 0
        var curIdx = 0
        while (curIdx != s.length) {
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) {
                exitProcess(-5)
            }
            curNode = trie[curNode][c]
            curIdx++
        }
        return curNode
    }

    fun add(s: String, hahaCount: Long, prefix: String, suffix: String) {
        var curNode = 0
        var curIdx = 0
        while (curIdx != s.length) {
            val c = s[curIdx] - 'a'
            if (trie[curNode][c] == -1) {
                trie[curNode][c] = numNodes++
            }
            curNode = trie[curNode][c]
            curIdx++
        }
        numHaHa[curNode] = hahaCount
        this.suffix[curNode] = suffix
        this.prefix[curNode] = prefix
    }
}