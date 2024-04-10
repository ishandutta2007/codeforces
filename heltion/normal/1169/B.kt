import kotlin.system.exitProcess

fun main() {
    var s = readLine()!!.split(' ').map{it.toInt()}
    var (n, m) = s
    var ms = mutableSetOf(Pair(0, 0))
    repeat(m) {
        s = readLine()!!.split(' ').map{it.toInt()}
        var(a, b) = s
        var ns = mutableSetOf<Pair<Int, Int>>()
        for(p in ms){
            if(p.first == 0){
                ns.add(Pair(a, 0))
                ns.add(Pair(b, 0))
            }
            else if(p.second == 0){
                if(p.first == a || p.first == b) ns.add(p)
                else {
                    ns.add(Pair(p.first, a))
                    ns.add(Pair(p.first, b))
                }
            }
            else if(p.first == a || p.first == b || p.second == a || p.second == b)
                ns.add(p)
        }
        if(ns.size == 0){
            print("NO")
            exitProcess(0)
        }
        ms = ns
        //for(p in ms) print("${p.first} ${p.second}\n")
        //print("\n")
    }
    print("YES")
}