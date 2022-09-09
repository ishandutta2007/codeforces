class Tree(){
    var min = 0L
    private var add = 0L
    private var l = 0
    private var r = 0
    var left : Tree? = null
    var right : Tree? = null
    constructor(l : Int, r : Int) : this() {
        this.l = l
        this.r = r
        if(l < r){
            val m = (l + r) / 2
            left = Tree(l, m)
            right = Tree(m + 1, r)
        }
    }
    private fun add(v : Long){
        add += v
        min += v
    }
    private fun pushDown(){
        if(l < r){
            left!!.add(add)
            right!!.add(add)
        }
        add = 0L
    }
    fun add(L : Int, R : Int, v : Long){
        if((l >= L) and (r <= R)) add(v)
        else{
            pushDown()
            val m = (l + r) / 2
            if(L <= m) left!!.add(L, R, v)
            if(R > m) right!!.add(L, R, v)
            min = minOf(left!!.min, right!!.min)
        }
    }
}
fun main(){
    val n = readLine()!!.toInt()
    val p = readLine()!!.split(' ').map{it.toInt() - 1}
    val a = readLine()!!.split(' ').map{it.toLong()}
    val root = Tree(0, n)
    for(i in 0 until n) root.add(p[i] + 1, n, a[i])
    var ans = a[0]
    for(i in 0 until p.lastIndex){
        root.add(p[i] + 1, n, -a[i])
        root.add(0, p[i], a[i])
        ans = minOf(ans, root.min)
    }
    println(ans)
}