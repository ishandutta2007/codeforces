private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun isOk(str1: String, str2: String):String {
    if (str1.substring(1) == str2.take(str2.length - 1)) {
        return str1 + str2.last()
    }
    return ""
}

fun process(str1: String, str2: String, all: List<String>): MutableList<Char> {
    val str = isOk(str1, str2)
    if (str.isEmpty()) return emptyList<Char>().toMutableList()

    return all.map { if (str.startsWith(it)) 'P' else
            (if (str.endsWith(it)) 'S' else return emptyList<Char>().toMutableList()) }.toMutableList()
}

fun main(args: Array<String>) {
    val n = readInt()
    val arr = (1 until 2 * n - 1).map { readLn() }
    val sortedArr = arr.withIndex().sortedBy { -it.value.length }

    var ret = process(sortedArr[0].value, sortedArr[1].value, arr)
    if (ret.isEmpty()) ret = process(sortedArr[1].value, sortedArr[0].value, arr)

    for (i in (1 until 2 * n - 1) step 2)
        if (sortedArr[i] .value == sortedArr[i - 1].value) ret.set(sortedArr[i].index, 'S')

    println(ret.joinToString(""))
}