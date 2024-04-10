/**
 * We declare a package-level function main which returns Unit and takes
 * an Array of strings as a parameter. Note that semicolons are optional.
 */

fun main(args: Array<String>) {
    val a = readLine()!!.split(' ').map(String::toInt)
    val b = readLine()!!.split(' ').map(String::toInt)
    val n = a[0]
    val m = b[0]
    var c = Array<Int>(2001, {i -> 0})
    for (i in 1..n){
        c[a[i] + 1000] += 1
    }
    for (i in 1..m){
        c[b[i] + 1000] += 1
    }
    var ans = 0
    for (i in 0..2000){
        if (c[i] == 1)
            ans += 1
    }
    print(ans)
    for (i in 0..2000){
        if (c[i] == 1){
            print(" ")
            print(i - 1000)
        }
    }
    println()
}