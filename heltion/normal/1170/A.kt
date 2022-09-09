import kotlin.math.abs

fun rd() = readLine()!!
fun rdi() = rd().toInt()
fun rdis() = rd().split(' ').map{it.toInt()}.toMutableList()
fun main(){
    var q = rdi()
    repeat(q){
        var (x, y) = rdis()
        println("1 ${minOf(x, y) - 1} ${abs(x - y) + 1}")
    }
}