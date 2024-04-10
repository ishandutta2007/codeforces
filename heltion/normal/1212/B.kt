fun main() {
    readLine()
    var s = readLine()!!
    var c = Array(26 * 26){0}
    for(i in 0 until s.length - 1)
        c[(s[i] - 'A') * 26 + (s[i + 1] - 'A')] += 1
    var ma = 0
    var mi = 0
    for(i in 0 until c.size)
        if (c[i] > ma) {
            ma = c[i]
            mi = i
        }
    print("${'A' + mi / 26}${'A' + mi % 26}")
}