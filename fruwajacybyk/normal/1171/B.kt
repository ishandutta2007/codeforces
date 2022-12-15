import java.util.Scanner

fun main(args: Array<String>) {

    val reader = Scanner(System.`in`)
    var a:Int = reader.nextInt()
    var b:Int = reader.nextInt()
    var c:Int = reader.nextInt()
    var ans = a;
    if (ans > (b-1)) {
        ans = b-1;
    }
    if (ans > (c-2)) {
        ans = c-2;
    }
    ans = 3 * ans + 3;
    println("$ans")
}