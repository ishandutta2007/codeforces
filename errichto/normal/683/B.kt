fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    val sorted = Array(n, { i -> "nu" })
    for(i in 0..n-1) {
        var(imie, huh) = readLine()!!.split(' ')
        while(huh.length < 5)
            huh = "0"+huh
        sorted[i] = (huh + imie)
    }
    sorted.sort()
    for(i in 0..n-1) {
        for(j in 5..(sorted[i].length-1))
            print(sorted[i][j])
        println("")
    }
}