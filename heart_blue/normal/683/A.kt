/**
  * The `is` operator checks if an expression is an instance of a type and more.
  * If we is-checked an immutable local variable or property, there's no need
  * to cast it explicitly to the is-checked type.
  * See this pages for details:
  * http://kotlinlang.org/docs/reference/classes.html#classes-and-inheritance
  * http://kotlinlang.org/docs/reference/typecasts.html#smart-casts
 */
fun main(args: Array<String>) {
     var (a, x, y) = readLine()!!.split(' ').map(String::toInt)

    println(getStringLength(a, x, y))
}

fun getStringLength(a : Int, x : Int, y : Int): Int {
    if (x < 0 || y < 0)
    {
        return 2
    }
    if (x == 0 && y <= a)
    {
        return 1
    }
    if (y == 0 && x <= a)
    {
        return 1
    }
    if (x == a && y <= a)
    {
        return 1
    }
    if (y == a && x <= a)
    {
        return 1
    }
    if (x < a && y < a)
    {
        return 0
    }
    return 2
}