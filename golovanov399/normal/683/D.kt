/**
 * We declare a package-level function main which returns Unit and takes
 * an Array of strings as a parameter. Note that semicolons are optional.
 */

fun solve(): Unit {
    val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
    for (i in 1..n){
        if (p % i == 0 && p / i <= m){
            println("Yes")
            return
        }
    }
    println("No")
}

fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    for (i in 1..q){
        solve()
    }
}