fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    for(i in 1..n){
        val(a, b, c) = readLine()!!.split(' ').map(String::toInt)
        var x: Int
        x = 1
        for(j in 1..a){
            for(h in 1..b){
                if(j * h == c){
                    x = 2
                }
            }
        }
        if(x == 2)
            println("Yes")
        else
            println("No")
    }
}