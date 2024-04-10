fun main() {
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    repeat (readInt()) {
        val (n, m) = readInts()
        val a = Array(n){
            readInts()
        }
        val vis = Array(n){
            BooleanArray(m)
        }
        var cc = 0
        val ans = mutableListOf<Int>()
        fun dfs(u : Int, v : Int) : Boolean{
            if (u in 0 until n && v in 0 until m && !vis[u][v] && a[u][v] != 0) {
                vis[u][v] = true
                ans.add(a[u][v])
                if(dfs(u - 1, v)) ans.add(a[u][v])
                if(dfs(u + 1, v)) ans.add(a[u][v])
                if(dfs(u, v - 1)) ans.add(a[u][v])
                if(dfs(u, v + 1)) ans.add(a[u][v])
                return true
            }
            return false
        }
        for (i in 0 until n)
            for (j in 0 until m)
                if (a[i][j] != 0 && !vis[i][j]) {
                    cc += 1
                    dfs(i, j)
                }
        if (cc == 1) {
            val k = (ans.size + 1) / 2
            println("$k $k")
            val res = Array(k){
                IntArray(k)
            }
            for (i in 0..2 * k - 2) {
                val p = if (i == ans.size) ans[i - 1] else ans[i]
                for (j in 0 until k)
                    for (x in 0 until k)
                        if (j + x == i)
                            res[j][x] = p
            }
            for (ar in res) {
                for (x in ar) print("$x ")
                println()
            }
        }
        else println(-1)
    }
}