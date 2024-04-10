fun main(args: Array<String>) {
    var t = readLine()!!.toInt()
    repeat(t) {
        var (x, y) = readLine()!!.split(" ").map{ it.toLong() }
        var xp = x
        while (xp * 10 <= y) xp *= 10
        var ans = 0
        while (y > 0) {
          while (xp > x && xp > y) xp /= 10
          if (xp > y) break
          ++ans
          y -= xp
        }
        println(y + ans)
    }
}