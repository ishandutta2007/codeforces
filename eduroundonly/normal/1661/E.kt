// $time$
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    var warningActive = true
    var fakein = StringBuilder()

    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextLong(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextString():String{
        val ret = StringBuilder()
        while (true){
            c = char
            if(!isWhitespace(c)){ break}
        }
        ret.append(c)
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.append(c)
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
    fun rerouteInput(){
        if(warningActive){
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }

        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }
        if(withBruteForce){
            println("Brute force is active")
        }

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            onecase()
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)

fun buildableSegTree.segDivisionOrdered(l:Int, r:Int, act:(index:Int)->Unit){
    var left = l + n
    var right = r + n + 1
    var level = 0
    val L = mutableListOf<Int>()
    val R = mutableListOf<Int>()
    while(left < right){
        if(left and 1 != 0){

            L.add(left)
            left += 1
        }
        if(right and 1 != 0){
            right -= 1
            R.add(right)
        }
        left = left shr 1
        right = right shr 1
        level ++
    }
    for(i in L){
        act(i)
    }
    for(i in R.asReversed()){
        act(i)
    }
}
class buildableSegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val cid = IntArray(n * 2 + 1 ){data.empty}
    val ccount = IntArray(n * 2 + 1)

    constructor(withArray:Array<IntArray>):this(withArray.size){
        for(i in withArray.indices){
            val (here,herec) = data.getbase(withArray[i])
            cid[i+n] = here
            ccount[i+n] = herec
        }

        updateAll()
    }
    private fun updateNode(i:Int){
        cid[i] = data.combine[cid[i shl 1 ]][cid[(i shl 1) + 1]]
        val delta = data.combinedelta[cid[i shl 1 ]][cid[(i shl 1) + 1]]
        ccount[i] = ccount[i shl 1] + ccount[(i shl 1) + 1 ] - delta
    }
    fun queryFunctional(l:Int,r:Int):Int{
        var nowtype = data.getbase(intArrayOf(0,0,0)).first
        var nowcount = 0
        segDivisionOrdered(l,r){i ->
            val newtype = data.combine[nowtype][cid[i]]
            val newdelta = data.combinedelta[nowtype][cid[i]]
            val newcount = nowcount + ccount[i] - newdelta
            nowtype = newtype
            nowcount = newcount
        }
        return nowcount
    }
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun setValue(i:Int,value:Int){
        cid[n+i] = value
        updatePath(n+i)
    }
    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex

    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                act(left,level)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                act(right,level)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
    }


    val Int.leftNode:Int get(){
        // assert(this <= n )
        return this shl 1
    }
    val Int.rightNode:Int get(){
        // assert(this <= n)
        return (this shl 1) + 1
    }
    val Int.endpoints:Pair<Int,Int> get(){
        val offSet = this - this.takeHighestOneBit()
        val widthLevel = levels - (31 - this.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }


}
class DisjointUnionSets(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    var components:Int = n

    val successfulUnions:Int get() = n - components

    fun find(x: Int): Int {
        if (parent[x] != x) {
            parent[x] = find(parent[x])
        }
        return parent[x]
    }

    fun union(x: Int, y: Int):Boolean {
        val xRoot = find(x)
        val yRoot = find(y)
        if (xRoot == yRoot) return false
        components--
        if(size[xRoot] < size[yRoot]){
            parent[xRoot] = yRoot
            size[yRoot] += size[xRoot]
        }else{
            parent[yRoot] = xRoot
            size[xRoot] += size[yRoot]
        }
        return true
    }
    fun getsize(a:Int):Int{
        return size[find(a)]
    }

    var modified = mutableListOf<Int>()
    inline fun eachComponent(act:(Int)->Unit){
        for(i in 0 until n){
            if(parent[i] == i){
                act(i)
            }
        }
    }

    fun printAll(){
        val comps = Array(n){ mutableListOf<Int>()}
        for(i in 0 until n){
            comps[find(i)].add(i)
        }
        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
    }
}
inline fun product(a:List<Int>,act:(List<Int>)->Unit){
    val current = MutableList(a.size){0}
    while(true){
        act(current)
        val lastGood = (0 until a.size).lastOrNull{a[it]-1 != current[it]}
        if(lastGood == null){
            return
        }
        current[lastGood] += 1
        for(i in lastGood+1 until a.size){
            current[i] = 0
        }
    }
}


// -1 is not free
class data(val all:IntArray){



    companion object{
        val all = mutableMapOf<data,Int>()
        val forward = mutableListOf<data>()
        var combine = Array(0){IntArray(0)}
        var combinedelta = Array(0){IntArray(0)}
        var empty = -1
        fun getall(){
            product(List(6){7}){
                v ->
                val ret = v.toIntArray()
                for(i in ret.indices){
                    if(ret[i] == 6){
                        ret[i] = -1
                    }
                }
                for(i in listOf(0,1,3,4)){
                    if(ret[i] != -1 && ret[i+1] != -1 && ret[i] != ret[i+1]){
                        return@product
                    }
                }
                val nd = data(ret).normal()
                if(all[nd] == null){
                    all[nd] = all.size
                    forward.add(nd)
                }
            }


            val d = all.size
            combine = Array(d){ IntArray(d) }
            combinedelta = Array(d){IntArray(d)}

            for(left in 0 until d){
                for(right in 0 until d){
                    val L = forward[left]
                    val R = forward[right]
                    val (c,r) = L.merge(R)
                    combine[left][right] = all[c]!!
                    combinedelta[left][right] = r
                }
            }
            empty = getbase(intArrayOf(0,0,0)).first
        }
        fun getbase(a:IntArray):Pair<Int,Int>{
            val ret = IntArray(6)
            var pt = 0
            for(i in 0 until 3) {
                if(a[i] == 0){
                    ret[i] = -1
                }else {
                    if(i != 0 && ret[i-1] != -1){
                        ret[i] = ret[i-1]
                    }else{
                        ret[i] = pt
                        pt ++
                    }
                }
            }
            for(i in 0 until 3){
                ret[i+3] = ret[i]
            }
            return Pair(all[data(ret)]!!, pt)
        }
    }

    fun normal():data {
        val ret = all.copyOf()
        val found = mutableMapOf<Int,Int>()
        for(i in 0 until 6){
            if(ret[i] == -1) continue
            val v = ret[i]
            if(found[v] == null){
                found[v] = found.size
            }
            ret[i] = found[v]!!
        }
        return data(ret)
    }


    fun merge(other:data):Pair<data,Int>{
        val dsu = DisjointUnionSets(8)
        val R = other.all.copyOf()
        for(i in 0 until 6){
            if(R[i] != -1){
                R[i] += 4
            }
        }
        var things = mutableSetOf<Int>()
        for(a in all) {
            things.add(a)
        }
        for(b in R) {
            things.add(b)
        }
        things.remove(-1)
        val startsize = things.size
//        var reduced = 0
        for(i in 0 until 3){
            if(all[3+ i ] != -1 && R[i] != -1){
                dsu.union(all[3 + i], R[i])
            }

        }
        val ret = IntArray(6){
            val v = if(it < 3) all[it] else R[it]
            if(v == -1) -1 else dsu.find(v)
        }

        val newthings = mutableSetOf<Int>()
        for(a in all) {
            if(a != -1)
                newthings.add(dsu.find(a))
        }
        for(b in R) {
            if(b != -1)
                newthings.add(dsu.find(b))
        }
        val newsize = newthings.size
        val reduced = startsize - newsize
        return Pair(data(ret).normal(), reduced)
    }

    override fun equals(other:Any?):Boolean {
        if(this === other) return true
        if(javaClass != other?.javaClass) return false

        other as data

        if(!all.contentEquals(other.all)) return false

        return true
    }

    override fun hashCode():Int {
        return all.contentHashCode()
    }
}



fun debug(){}
const val withBruteForce = false
const val singleCase = true
fun main(){
//    TIME{
    data.getall()
//    }


    //813
    //862
//
//    just dei data.forward[813].merge(data.forward[862])
//    val (a,c) = data.getbase(intArrayOf(0,1,1))
//    val (b,d) = data.getbase(intArrayOf(0,0,0))
//    val x = data.forward[b].merge(data.forward[a])
//    just dei c + d - data.combinedelta[a][b]
    solve.cases{

        val n= getint
        val arr = Array(n){IntArray(3)}
        repeat(3){y ->
            val str = getstr
            for(i in 0 until n) {
                arr[i][y] = if(str[i] == '1') 1  else 0
            }
        }
        val st = buildableSegTree(arr)
        val q = getint
        repeat(q) {
            val l = getint - 1
            val r = getint - 1
            val ans = st.queryFunctional(l,r)
            put(ans)
        }



    }
    done()
}