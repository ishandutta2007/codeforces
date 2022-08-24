fun main(args: Array<String>) {
    val s: String = readLine()!!
    var needspace: Boolean = false
    var bigsize: Boolean = true
    var first: Boolean = true
    for (c in s) {
        when (c) {
            ' ' -> needspace = true
            '.' -> {
                needspace = true
                bigsize = true
                first = false
                print(".")
            }
            ',' -> {
                needspace = true
                bigsize = false
                first = false
                print(",")
            }
            else -> {
                if (needspace && !first){
                    print(" ")
                }
                if (bigsize){
                    print(c.toUpperCase())
                } else {
                    print(c.toLowerCase())
                }
                first = false
                needspace = false
                bigsize = false
            }
        }
    }
    println()
}