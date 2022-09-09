fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readIntArray() = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    repeat(readInt()){
        readIntArray()
        val a = readIntArray()
        val p = readIntArray().map{it - 1}.sorted()
        repeat(a.size){
            for(i in p)
                if(a[i] > a[i + 1]){
                    val tmp = a[i]
                    a[i] = a[i + 1]
                    a[i + 1] = tmp
                }
        }
        var ok = true
        for(i in 0 until a.lastIndex)
            if(a[i] > a[i + 1])
                ok = false
        println(if(ok) "YES" else "NO")
    }
}