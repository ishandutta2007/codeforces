const val mod = 998244353L
class Matrix{
    private val v : Array<LongArray> = Array(4){ LongArray(4) }
    operator fun times(m : Matrix) : Matrix{
        val res = Matrix()
        for(i in 0 until 4)
            for(j in 0 until 4)
                for(k in 0 until 4)
                    res.v[i][j] = (res.v[i][j] + v[i][k] * m.v[k][j]) % mod
        return res
    }
    fun setL(){
        for(i in 0 until 4)
            for(j in 0 until 4)
                if(i > j) v[i][j] = 1
    }
    fun setLe(){
        for(i in 0 until 4)
            for(j in 0 until 4)
                if(i >= j) v[i][j] = 1
    }
    fun setG(){
        for(i in 0 until 4)
            for(j in 0 until 4)
                if(i < j) v[i][j] = 1
    }
    fun setGe(){
        for(i in 0 until 4)
            for(j in 0 until 4)
                if(i <= j) v[i][j] = 1
    }
    fun get() : Long{
        var res = 0L
        for(i in 0 until 4)
            for(j in 0 until 4)
                res = (res + v[i][j]) % mod
        return res
    }
    fun getV() : Array<LongArray>{
        return v
    }
}
fun main(){
    val (n, q) = readLine()!!.split(' ').map { it.toInt() }
    val a = (listOf(0) + readLine()!!.split(' ').map { it.toInt() } + listOf(0)).toIntArray()
    val nodes = Array(n * 4){Matrix()}
    fun update(v : Int, tl : Int, tr : Int, p : Int, x : Matrix){
        if(tl == tr) nodes[v] = x
        else{
            val tm = (tl + tr) / 2
            if(p <= tm) update(v * 2, tl, tm, p, x)
            else update(v * 2 + 1, tm + 1, tr, p, x)
            nodes[v] = nodes[v * 2 + 1] * nodes[v * 2]
        }
    }
    fun change(i : Int){
        if(i == 0) return
        val x = Matrix()
        if(a[i] == 1){
            if(a[i + 1] == 1) x.setLe()
            else x.setL()
        }
        else{
            if(a[i + 1] == 0) x.setGe()
            else x.setG()
        }
        update(1, 1, n - 1, i, x)
    }
    for(i in 1 until n) change(i)
    repeat(q){
        val p = readLine()!!.toInt()
        a[p] = 1 - a[p]
        change(p)
        change(p - 1)
        println(nodes[1].get())
    }
}